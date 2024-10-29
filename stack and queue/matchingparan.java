import java.util.Stack;

class Solution {
    public boolean isValid(String s) {
        int len = s.length();
        Stack<Character> stack = new Stack<>();

        for(int i = 0; i< len ; i++)
        {
            char currentChar = s.charAt(i);

            /*

            if ( currentChar == '{' || currentChar == '(' || currentChar == '['  ){
                stack.push(currentChar);
            }
            else{
                if (stack.isEmpty()) {
                    return false; 
                }


                char temp = stack.peek();
                if( (currentChar == '}' && temp == '{') ||
                    (currentChar == ')' && temp == '(') ||
                    (currentChar == ']' && temp == '[')
                   )
                {
                    stack.pop();
                }
                else{
                    return false;
                }
            }
            */

            if (currentChar == '{') stack.push('}');
            else if (currentChar == '[' ) stack.push(']');
            else if (currentChar == '(') stack.push(')');
            else 
            {
                if (stack.empty() || currentChar != stack.pop() ) return false;

            }
        }

        
        return (stack.empty());
    }
}