for FILE in $(ls test/*.txt)
do
    for i in 1 2 3 4 5 10 32 64 100 1000 10000 100000
    do
        echo -n  "$FILE : BUFFER_SIZE=$i : "
            gcc get_next_line.c main.c -Wall -Wextra -Werror  -D BUFFER_SIZE=$i -o get_next_line -g -fsanitize=address
            ./get_next_line $FILE > tmp
            difference=`diff $FILE tmp`
            if [ -z $difference]
                then echo "ok"
                else echo $difference
            fi
    done
done