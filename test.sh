echo "((1+1))" | ./calculator > out.txt
./checker testdata/in out.txt testdata/6.ans
echo "(1+1)*2" | ./calculator > out.txt
./checker testdata/in out.txt testdata/7.ans
echo "(1+1)^2" | ./calculator > out.txt
./checker testdata/in out.txt testdata/8.ans
echo "((2-1)*2+1)^2" | ./calculator > out.txt
./checker testdata/in out.txt testdata/9.ans
echo "(((2-1)*2+1)^2-1)/2" | ./calculator > out.txt
./checker testdata/in out.txt testdata/10.ans
echo "-1+1" | ./calculator > out.txt
./checker testdata/in out.txt testdata/11.ans
echo "1+(-1)" | ./calculator > out.txt
./checker testdata/in out.txt testdata/12.ans
echo "(((-2-1)*2+1)^2-1)/2" | ./calculator > out.txt
./checker testdata/in out.txt testdata/13.ans
echo "0.1-1" | ./calculator > out.txt
./checker testdata/in out.txt testdata/14.ans
echo "0.1-0.1" | ./calculator > out.txt
./checker testdata/in out.txt testdata/15.ans
echo "0.1^0.1" | ./calculator > out.txt
./checker testdata/in out.txt testdata/16.ans
echo "sqrt9" | ./calculator > out.txt
./checker testdata/in out.txt testdata/17.ans
echo "sqrt(8+1)" | ./calculator > out.txt
./checker testdata/in out.txt testdata/18.ans
echo "8^(1/3)" | ./calculator > out.txt
./checker testdata/in out.txt testdata/19.ans
echo "8^-1" | ./calculator > out.txt
./checker testdata/in out.txt testdata/20.ans
echo "1+(+1+1)" | ./calculator > out.txt
./checker testdata/in out.txt testdata/21.ans