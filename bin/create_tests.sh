#!/bin/bash
num_files=$1
output_dir="files"

mkdir -p "$output_dir"

for ((i = 1; i <= num_files; i++)); do
    filename="$output_dir/test_$i.txt"
    cat > "$filename" <<EOL
\$input
input_file_$i.txt
\$output
output_file_$i.txt
\$search
search_string_$i
\$replace
replace_string_$i
EOL
    echo "Created $filename"
done

echo "Generated $num_files files in $output_dir/"