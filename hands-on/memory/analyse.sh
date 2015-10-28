#!/bin/bash

if [ $# -lt 1 ]; then
    exit 1
fi

igprof-analyse --sqlite -d -v -g -r MEM_TOTAL $1 | sqlite3 ~/public_html/cgi-bin/data/${1}_tot.sql3
igprof-analyse --sqlite -d -v -g -r MEM_LIVE $1 | sqlite3 ~/public_html/cgi-bin/data/${1}_live.sql3
igprof-analyse --sqlite -d -v -g -r MEM_LIVE --value peak $1 | sqlite3 ~/public_html/cgi-bin/data/${1}_live_peak.sql3
