/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
*/


class Solution {
    public boolean isValid(String s) {
        Stack<Character> stk = new Stack<>();
        for(int i=0;i<s.length();i++) {
            if(s.charAt(i)==')' && !stk.isEmpty()){
                if(stk.peek()=='(') stk.pop();
                else return false;
            }
            else if(s.charAt(i)=='}' && !stk.isEmpty()){
                if(stk.peek()=='{') stk.pop();
                else return false;
            }
            else if(s.charAt(i)==']' && !stk.isEmpty()){
                if(stk.peek()=='[') stk.pop();
                else return false;
            }
            else stk.push(s.charAt(i));
        }
        if(stk.size()==0) return true;
        else return false;
    }
}
