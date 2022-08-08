## ctoyeet
### [WIP] C program that converts C syntax to 'yeet looking' syntax
---

## What breaks it
- using multiple files and headers
- writing code between `#define`s
- `' '*2;`
- many more!

but,

[**Can convert itself**](https://github.com/njegg/ctoyeet/blob/main/src_but_yeeted/combined_files_yeeted.c) and still work

## Features

Convets this:
```C
char *generate(int n)
{
    n++;
    int bit = 16;
    int yeet_size = 4;
    while (bit <= INT_MAX) {
        if (n < bit) break;
        bit <<= 1;
        yeet_size++;
    }
    
    char *yeet = (char*) malloc(sizeof(char) * yeet_size);

    int capital;
    for (int i = 0; i < yeet_size; i++) {
        capital = n % 2; // first right bit
        if (i == 0) {
            yeet[i] = capital ? 'Y' : 'y';
        } else if (i == yeet_size - 1) {
            yeet[i] = capital ? 'T' : 't';
        } else {
            yeet[i] = capital ? 'E' : 'e';
        }

        n >>= 1;
    }

    return yeet;
}
```

To this:

```C
Yeet  yEet  YEet 
yeEt 
    YeEt 
    yEEt  YEEt  yeeT  YeeT 
    yEEt   yEeT  yeeT   YEeT 
    yeET  YeET  yEET  YEET  yeEt  
        yeeeT  YeeeT  yEeeT  YEeeT  yeEeT 
        YEEt   YeEeT  yEEeT 
        YEEeT 
    yeeET 
    
    Yeet   YeeET  yeeT    yEeET  YEeET  yeEET  YeEET 

    yEEt    yEEET 
    YEEET  yeeeeT  YeeeeT  yeeT     yEeeeT  YeeeeT   yEeeT   YEeeeT  yeEeeT  yeEt   
        YeEeeT  yeeT      yEEeeT  YEEeeT  yeeEeT          yeeeT   YeeEeT  yEeEeT  YEeEeT  yeEt    
            yeEEeT  yeeT       YeEeeT   YeEEeT  yEEEeT  YEEEeT  yeeeET 
        yeeET   YeeeET  yeeeT    YeeEeT   yEeEeT   yEeT   yEeeET  YEeeET  yeEt     
            yeEEeT   yeeT        YeEeeT    YeEEeT   yeEeET  YEEEeT   YeEeET 
        yeeET    YeeeET   yeEt      
            yeEEeT    yeeT         YeEeeT     YeEEeT    yEEeET  YEEEeT    YEEeET 
        yeeET    

        yEEeeT   yeeEET  yEEeT  
    yeeET     

    YeeEET  yEeEET 
yeeET      
```

Using this...

```C
#define YeeEeT (i
#define YEeeeeT &n);
#define YEeEET main_test_generate(void)
#define YeeeT (n
#define yEEEET "> "
#define yeEeET 'T'
#define yeeEET >>=
#define YeeEeeT 20;
#define yEET <=
#define YEeET malloc(sizeof(char)
#define YEEeET 'e';
#define yEEeET 'E'
#define yEeeeT 0;
#define YEeeT bit)
#define YeeeeT i
#define yEeEET yeet;
#define yEet *generate(int
#define yeeeT if
#define YeeeET else
#define yEEeeT n
#define YEeeeT yeet_size;
#define YEet n)
#define yEEeeeT n,
#define YeeT 16;
#define YeEeeeT "generated yeet for %i = %s\n\n"
#define YEeeET 1)
#define YeeeeeT "%i"
#define YeEeeT capital
#define yeEt {
#define yeEeT break;
#define yeeET }
#define yEeEeT ==
#define YEeT 4;
#define yEEeT 1;
#define yEeT yeet_size
#define YEEeeT %
#define yeEeeT i++)
#define YeeET *yeet
#define YEEeT yeet_size++;
#define YEeEeeT generate(i));
#define YEEeeeT yeet);
#define yeEET *
#define yEeeeeT ,
#define yEeeET -
#define yeeEeeT main_test_n_generate(void)
#define YeEEET printf(
#define yEEET capital;
#define yeEEeT yeet[i]
#define yEeEeeT "%s\n"
#define yEEEeT 'Y'
#define YEEEeT :
#define Yeet char
#define yEeET (char*)
#define yEeeT <
#define yeeT =
#define YeEt n++;
#define yeEEET >=
#define YeET (bit
#define YeEEeT ?
#define yeeeET 'y';
#define yeeEeT 2;
#define YEET INT_MAX)
#define YEEt bit
#define yeeeeT (int
#define YeEeT <<=
#define YEEEET );
#define YeEeET 't';
#define YeeEET return
#define YEEET for
#define YeEET yeet_size);
#define yeeeeeT scanf(
#define yEEt int
#define yeEeeeT generate(n);
#define YEeEeT 0)
#define yeET while
```
