#!/bin/bash

git add .

for file in $(git diff --cached --name-only); do
    git reset HEAD .
    git add "$file"
    git commit -m "$(basename "$file")"
done

git push origin main