/**
 * Question : 7 Reverse Integer
 * Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 

Constraints:

-231 <= x <= 231 - 1
 */

/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    const minIntegerLength = -(2**31)
    const maxIntegerLength = (2**31)

    let ans = 0
    while (x !== 0){
        // Get last digit from given number
        let digit = x%10
        if((ans > Math.trunc(maxIntegerLength/10)) || (ans < Math.trunc(minIntegerLength/10))) {
            return 0
        }
        ans = (ans*10) + digit
        x = Math.trunc(x/10)
    }
    return ans
};