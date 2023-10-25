#!/bin/bash

dl_spbu_s_e () {
    curl $1 -s --compressed -H 'User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10.15; rv:109.0) Gecko/20100101 Firefox/118.0' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,*/*;q=0.8' -H 'Accept-Language: ru-RU,ru;q=0.8,en-US;q=0.5,en;q=0.3' -H 'Accept-Encoding: gzip, deflate, br' -H 'DNT: 1' -H 'Connection: keep-alive'
}

dl_spbu_oop () {
    if [[ $3 == true ]];
    then
        dl_spbu_s_e $1 | grep -o -E "$2" | sed "s/'//g" | sort | uniq | sort -R | head -n 10
    else
        dl_spbu_s_e $1 | grep -o -E "$2" | sed "s/'//g" | sort | uniq
    fi
}

function download {
    for u in $1;
    do
        if ! wget -P $2 "$(dl_spbu_oop $u "https://nc\.spbu\.ru/[^ >]+/download" false)";
        then
            >&2 echo Cannot download $u
            return 2
        fi
    done
}

function unpack {
    for f in $1/*;
    do
        if [ -f $f ];
        then
            unar -f $f -o $1
        fi
    done
}

for param in $@;
do
    shift
    case $param in
    --source)
        set -- $@ -s
        ;;
    --destination)
        set -- $@ -d
        ;;
    --probe)
        set -- $@ -p
        ;;
    *)
        set -- $@ $param
        ;;
    esac
done

param_s=https://spbu.ru/sveden/education
param_d=./content
param_p=false
while getopts "s:d:p" OPTION;
do
    case $OPTION in
        s)
            param_s=$OPTARG
            ;;
        d)
            param_d=$OPTARG
            ;;
        p)
            param_p=true
            ;;
        :)
            exit 1
            ;;
        *)
            exit 1
            ;;
    esac
done

for u in $(dl_spbu_oop $param_s "https://nc\.spbu\.ru/[^ >]+" $param_p); do
    download $u $param_d
done

unpack $param_d