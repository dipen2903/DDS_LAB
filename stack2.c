#include<stdio.h>
#include<string.h>

char infix[10],postfix[10],st[10];

int top = -1;
int l,i,j;

char c,k,ct;`

void push(char c1){
	top++;
	st[top] = c1;
}
char pop(){
	char c1;
	c1 = st[top];
	return(c1);
}
int prio(char c1){
	if(c1 == '+' || c1 == '-'){
		return 1;
		
	}
	else if(c1 == '*'|| c1 == '/'){
		return 2;
	}
	
}
 
int main(){
	printf("give infix exprn \n");
	scanf("%s",infix);
	
	l = strlen(infix);
	printf("infix string length is %d\n",l);
	j=0;
	for(i=0;i<1; ){
		c = infix[i];
		ct = st[top];
		if(c=='2' || c=='7'  || c=='6' || c=='5' || c=='4' || c=='1' || c=='3'  || c=='4'){
			postfix[j++]=c;
			i++;
		}
		else if(prio(c) > prio(ct) || (top == -1)){
			push(c);
			i++;
		}
		else{
			k = pop();
			postfix[j++]= k;
		}
	}
	while(top != -1){
		k = pop();
		postfix[j++]=k;
	}
	printf("final postfix exprn is %s \n",postfix);
	return 0;
}
