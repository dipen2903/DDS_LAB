# include <stdio.h>
# include <string.h>

char infix[100], postfix[100],st[100];  

int top = -1;
int l,i,j;

char c,k,ct;

void push(char c1)
{
    top++;
    st[top] = c1;
}

char pop()
{
  char c1;
  
  c1 = st[top];
  top--;
  
  return (c1);
}

int IsDigit(char c1)
{
  if(c1 == '1' || c1 == '2' || c == '3' ||
   c == '4' || c == '5' ||c == '6' || c == '7' || c == '8' ||c == '9')
    return 1;
  return 0;
}

int prio (char c1)
{
    if(c1 == '+' || c1 == '-')
        return 1;
    else if(c1 == '*' || c1 == '/')
        return 2;
    else if(c1 == '(' || c1 == ')')
        return 0;
}

int main() 
{
    printf("give infix exprn \n");
    scanf("%s",infix);

    l = strlen(infix);
    printf("infix string length is %d \n",l);
    
    j = 0;
    
    for(i=0; i<l; ) // Think Over why i is not incremented here
    {
        c = infix[i];
        printf("Working on character %c \n", c);
        
        if(IsDigit(c)) 
        {
          postfix[j++] = c;
          i++;
        }
        else if(c == '(')
        {
            push(c);
            i++;
        }
        else if(c == ')')
        {
          do
          {
            k = pop();
            if(k == '(')
                break;
            postfix[j++] = k;  
          }while(top != -1); 
          //pop();
          i++;
        }
        else if (top == -1 || prio(c) > prio(st[top]) )
        {
          push(c);
          i++;
        }
        else
        {
          k = pop();
          postfix[j++] = k;// dont increment i
          //i++; Think Over why i is not incremented here
        }    
    }
    while(top != -1)
    {
         k = pop();
         postfix[j++] = k;
    }   
    printf("final postfix exprn is %s \n",postfix);
    return 0;
}
