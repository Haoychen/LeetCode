/*
There are n bulbs that are initially off. You first turn on all the bulbs. 
Then, you turn off every second bulb. On the third round, you toggle every 
third bulb (turning on if it's off or turning off if it's on). For the ith 
round, you toggle every i bulb. For the nth round, you only toggle the 
last bulb. Find how many bulbs are on after n rounds.

Example:

Given n = 3. 

At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 

So you should return 1, because there is only one bulb is on.
*/

/*
对于第n个灯泡，只有当次数是n的因子的之后，才能改变灯泡的状态，即n能被当前次数整除，
比如当n为36时，它的因数有(1,36), (2,18), (3,12), (4,9), (6,6), 可以看到前四个
括号里成对出现的因数各不相同，括号中前面的数改变了灯泡状态，后面的数又变回去了，
等于锁的状态没有发生变化，只有最后那个(6,6)，在次数6的时候改变了一次状态，
没有对应其它的状态能将其变回去了，所以锁就一直是打开状态的。所以所有平方数都有
这么一个相等的因数对，即所有平方数的灯泡都将会是打开的状态。

那么问题就简化为了求1到n之间完全平方数的个数
*/


class Solution {
public:
    int bulbSwitch(int n) {
        int res = 1;
        while (res * res <= n) ++res;
        return res - 1;
    }
};
