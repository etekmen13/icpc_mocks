#!/bin/bash

file="main.cpp"
output=$(echo "$file" | sed "s/\..*//")
ARGS=" $* "

FLAGS=""

if [[ "$ARGS" == *" --debug "* ]]; then
  FLAGS="-DDEBUG"
fi


g++ -o "$output" "$file" -std=gnu++20 -fsanitize=address -Wall $FLAGS
i=1
for in_file in tests/*.in; do
    if [[ "$ARGS" == *" --debug "* ]]; then
        echo "===== Test Case $i ====="
        ((i++))
        ./$output < "$in_file"
        continue

    fi
    
    name=$(echo "$in_file" | sed "s/\..*//")
    out_file=$(echo "$name".ans)
    tmp=$(mktemp)
    ./$output < "$in_file" > "$tmp"
    
    if diff -B --report-identical-files --side-by-side "$tmp" "$out_file" > /dev/null; then
        echo "OK"
    else
        echo "FAIL"
        diff -B --report-identical-files --side-by-side "$tmp" "$out_file" 
    fi
    rm "$tmp"
done
