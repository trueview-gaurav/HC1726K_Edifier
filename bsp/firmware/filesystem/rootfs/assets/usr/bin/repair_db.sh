#!/bin/sh

db_path=$1
factory_db_path=$2
new_db=/usrdata/new_666888.db

result=$(sqlite3 $db_path "PRAGMA integrity_check")

if [ "$result" != "ok" ] ; then

		printf "$db_path is broken.\n"
		printf "copy $factory_db_path to $db_path.\n"
		cp -f $factory_db_path $db_path
		result=$(sqlite3 $db_path "PRAGMA integrity_check")
		printf $result
else
        printf $result
fi