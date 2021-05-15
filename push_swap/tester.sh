#! /bin/bash #shebang
ARG=$(./random_numbers 5 1)
./push_swap $ARG
#| ./checker $ARG
# echo $ARG > b

# ./checker $ARG
# ./push_swap $ARG