./calc < negroot.txt > o5.txt 2> e5.txt
if [ $? -ne 0 ]; then
    echo "invalid exit code in test_negroot.sh" $?
    rm o5.txt
    rm e5.txt
    exit 1
fi

./calc_x86 < negroot.txt > o6.txt 2> e6.txt
if [ $? -ne 0 ]; then
    echo "invalid exit code in test_negroot.sh" $?
    rm o6.txt
    rm e6.txt
    exit 1
fi

diff o5.txt o6.txt
if [ $? -ne 0 ]; then
    echo "invalid exit code in test_negroot.sh" $?
    rm o5.txt
    rm o6.txt
    rm e5.txt
    rm e6.txt
    exit 1
fi

rm o5.txt
rm o6.txt
rm e5.txt
rm e6.txt

exit 0

