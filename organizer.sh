#!/bin/sh
echo "Starting organizer script"

#Get file name
f=$(find  . -maxdepth 1 -type f -name "$1*")
f="${f#*/}"
echo "Found file $f"

#get directory name
n="${1::-2}"
printf -v n "%03d" $n
d="Volume$n"
echo "Moving to directory $d"
#create directory if necessary
if [ -d "$d" ]; then 
	echo "Directory exists already"
else
	echo "Creating directory"
	mkdir "$d"
fi

#copy file
mv "$f" "$d/$f"
git add "$d/$f"
git commit -m "Solved $1"
git push