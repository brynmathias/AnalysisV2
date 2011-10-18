#!/bin/bash
EXPECTED_ARGS=1
E_BADARGS=65
if [ $# -ne $EXPECTED_ARGS ]
then
  echo "Usage: `basename $0` {module name}"
  exit $E_BADARGS
fi

if [ -d ./$1/ ]
then
	echo "Error: Folder $1 exists."
	exit $E_BADARGS
fi

echo "Copying common files..."
cp -R ./tools/module_template ./$1

echo "Cleaning up CVS directories..."
find ./$1/ -depth -name 'CVS' -exec rm -rf '{}' \; -print
sed -i "s/TMP_MODULE_NAME/$1/g" ./$1/Debug
sed -i "s/TMP_MODULE_NAME/$1/g" ./$1/Release
sed -i "s/TMP_MODULE_NAME/$1/g" ./$1/src/common/Python.cc
