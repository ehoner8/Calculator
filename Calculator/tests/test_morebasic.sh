./calc < more_equations.txt > o3.txt 2> e3.txt
if [ $? -ne 0 ]; then
    echo "invalid exit code in test_basic.sh" $?
    rm o3.txt
    rm e3.txt
    exit 1
fi

./calc_x86 < more_equations.txt > o4.txt 2> e4.txt
if [ $? -ne 0 ]; then
    echo "invalid exit code in test_morebasic.sh" $?
    rm o4.txt
    rm e4.txt
    exit 1
fi

diff o1.txt o2.txt
if [ $? -ne 0 ]; then
    echo "invalid exit code in test_morebasic.sh" $?
    rm o3.txt
    rm o4.txt
    rm e3.txt
    rm e4.txt
    exit 1
fi

rm o3.txt
rm o4.txt
rm e3.txt
rm e4.txt

exit 0

