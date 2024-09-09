./calc < basic_equation.txt > o1.txt 2> e1.txt
if [ $? -ne 0 ]; then
    echo "invalid exit code in test_basic.sh" $?
    rm o1.txt
    rm e1.txt
    exit 1
fi

./calc_x86 < basic_equation.txt > o2.txt 2> e2.txt
if [ $? -ne 0 ]; then
    echo "invalid exit code in test_basic.sh" $?
    rm o2.txt
    rm e2.txt
    exit 1
fi

diff o1.txt o2.txt
if [ $? -ne 0 ]; then
    echo "invalid exit code in test_basic.sh" $?
    rm o1.txt
    rm o2.txt
    rm e1.txt
    rm e2.txt
    exit 1
fi

rm o1.txt
rm o2.txt
rm e1.txt
rm e2.txt

exit 0

