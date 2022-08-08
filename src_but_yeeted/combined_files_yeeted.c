#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <ctype.h>

#define NOKEY 1<<31

#define MAX_LINE 256
#define GO_TO_NEW_LINE 1
#define FIND_END_OF_COMMENT 2

#define YEeeEEEeT FILE*
#define YeeEeeEeT case
#define YEeeeeT V
#define yeEEeeEeT '*':
#define yEeEeT (i
#define yeEeeEEeT *(cp
#define YeEEEEET "\n"
#define YeEEeeET skip_to_code(FILE
#define yeeEeeeT (node**)
#define YEEeEeT key,
#define YEEEeEET SEEK_CUR);
#define yeEeeEET fopen(write_file,
#define YeeEEeEeT 1);
#define YeEeEeeeT *cp
#define YeeeeEET "out.c"
#define YEEeEeET *fr
#define yeEEeeET find_end_of_comment(char
#define yEEEEEeT res->res->next;
#define YeEEeEeT new_node->next
#define yEeEeEET fw);
#define YEEeeeeT map->table
#define yEEeeeeET "#define %s %s\n"
#define yeeEEEEeT '#'
#define yeeEEEET yeet,
#define yeEEEeET args[1]);
#define yEEeeeET *,
#define yEeeT (n
#define YeeEeEeT 128);
#define yEEeeEeT (node*)
#define yeeeEET *cur
#define YeEeET 'T'
#define yEeeeEEeT "%[^\n\" ]s"
#define YEEEEEeeT strcat(yeet,
#define yeEEeeeeT *yeet,
#define YEEEeEEeT (cp)
#define YEeEeeEeT GO_TO_NEW_LINE;
#define yEEEEeeeT continue;
#define YEEeeEeT malloc(sizeof(node));
#define yeEeEET (strcmp(cur->key,
#define yEEEeET hash
#define YeeEET >>=
#define YeEeeeeET fprintf(f,
#define yeEEeEET "File is empty\n"
#define YEeeeeET new_val;
#define YEEEEET <<
#define yeeeEeT void
#define yeEEeEEeT line_cnt
#define YEeeEEeeT *cp);
#define YEeEeEeeT added
#define YeeEeeeeT free(key);
#define YEeEEeeT (cur)
#define YEET <=
#define yeeeeeEeT " "
#define YEeeEeET (argc
#define yeeeeeET map->size--;
#define YEeEeEeT strcpy(new_node->key,
#define yEEeEEEeT c
#define YEEEeeeT (!map)
#define YEEeEEEeT fgetc(fr);
#define yeeeEeEeT strcpy(key,
#define YEeeeEeeT fr);
#define YEEeEEET line,
#define yeEET malloc(sizeof(char)
#define YeEEeeEeT FIND_END_OF_COMMENT;
#define yeEeeEeT (exists)
#define YEeEeeeeT *line,
#define yEeeEEET *key
#define yeeEeEeT new_node->key
#define yEeeeeT key;
#define yeeEET 'e';
#define YEEeET 'E'
#define YEeeeT 0;
#define YEEeeeeET cur->val,
#define YeeEeEEeT **cpp,
#define yEeEEEeeT "READ: %s\n"
#define yEeEEEET (DEBUG_INFO)
#define YeEEEEeT res->prev->next
#define yeEeT bit)
#define yeeEeeeET cur->key);
#define yeEeEeEeT "\""
#define YEEeEEeT key)];
#define yEeeeT i
#define yEeeEEEeT handle_includes_and_defines(FILE*
#define YEeeeeeeT hm_destroy(map);
#define YeeEEEET fr,
#define yEEEEeET *write_file;
#define yEeeEeEeT '\"')
#define YeeEeeET write_to_file_from_map(hashmap
#define yeEeEEeT (!res->prev)
#define YEeEET yeet;
#define yEet *generate(int
#define yEEEeeEeT default:
#define yEEEEET ((hash
#define YeeeT if
#define YeeeEEET *yeet;
#define YeEEeeeT free(map->table);
#define YeEeEeT hm_put(hashmap
#define YEeEeeT size;
#define yEeeET else
#define yeEEEEEeT fgets(buf,
#define yeEeeeET DEBUG_INFO
#define YEEeeT n
#define yeeeEEET hm_create_size(101);
#define yeeeeEET args[2];
#define YEEEeeET handle_includes_and_defines(FILE
#define yEEeeeeT malloc(sizeof(hashmap));
#define yeEeeT yeet_size;
#define yeEt n)
#define yeeeeEEeT buf);
#define yeeEEEeeT fprintf(fw,
#define yEEEEEET (status
#define yEeEEeT key);
#define YEeEEeeeT EOF)
#define yeeeEeeeT (fgets(line,
#define yEEEeeET add_defines(FILE
#define YEEEeeT table_size);
#define yeEEEeeeT (isspace(*cp))
#define YeEeEeeT !=
#define YeeeEeeT "Map may not be initialised. Use hm_create_size(size_t table_size).\n"
#define yeeEEET cur->next;
#define yEeT 16;
#define YEeeeEEeT '\"'
#define yeEEeEeeT hm_put(map,
#define yEEeEeeeT line;
#define yEEeEEET fill_map(map,
#define YEeEeEEeT *cpp;
#define yeEEEEeeT (!yeet)
#define yEeEeEeeT generate(map->size);
#define YEEeEET (strcmp(cur->next->key,
#define yEeeEET (!cur)
#define YEeeeET *prev;
#define yeEeET 1)
#define yEEEeEEeT "*/"
#define yeeEeEeeT EXIT_FAILURE;
#define yEeEeEeT new_node->val
#define yeEeeeeT *map
#define YeEEEeT hm_get(hashmap
#define yeEeeeeET *f,
#define yeeEeEEeT cp;
#define yEEeEeEeT 1,
#define YeeeEeEeT ""
#define YeEEEEeeT "Not in map: '%s'\n"
#define YEEEeeeeT *fw)
#define yEeeeeET res->res->val
#define YEEEeEeT new_node;
#define yEeeeeeT hash)
#define yEEEeeT *hm_create_size(size_t
#define yEeEEeEeT cp
#define yeEEEEeT res->res;
#define yEEeEeeT NULL)
#define yEeeeEeT exists
#define YEEeeeT hashmap
#define yEEeeT capital
#define YeEt {
#define yeeEeeeeT (key)
#define yEEEeEET -1,
#define YeEeeeT *next;
#define YeEeT break;
#define YEeEEEEeT ungetc(c,
#define YeeET }
#define YEEEEEET EXIT_SUCCESS)
#define YEEEEEeT free(del);
#define YEEeEeeT "%i -> [ "
#define yEEEEeT unsigned
#define YEEeeeEeT (*(cp
#define YeeEEEeeT "%c"
#define YEeeeEET fw
#define YeeeEEeT (!res->res)
#define yeeeEEEeT *cpp
#define yEeEeeeeT status;
#define YEEeeEEeT *line_pointer_pointer
#define yEEeeEET (!fw)
#define yeeEEeET fopen(args[1],
#define YeeEeeT size_t
#define YeEeEEEeT (1)
#define YEeEeT ==
#define YeeeeeeET fscanf(f,
#define yEEeEEeeT rewind(fr);
#define YEeEEeET "Cant open file: \"%s\", maybe it doesn't exist\n"
#define YEeeEeeT map->table_size;
#define YEEEET struct
#define YeEeeeeT (hashmap*)
#define yeET 4;
#define yEeeEeET **args)
#define yEEEEeeT cur->val);
#define YEeeEeT hm_print(hashmap*
#define YEeeeeeET f);
#define yeeeeeeET fgetc(f);
#define YEEEEeEeT sscanf(cp,
#define yEEEeEeeT "%s: '%s' : '%s'\n"
#define YeEEEeeeT cp++;
#define YEEeT 1;
#define YEEeeEeeT line);
#define YeeEeET (search_chain_res*)
#define YEeT yeet_size
#define yEeEEeeeT *cp!=
#define yeEEeeeT *map)
#define yeeEeT %
#define YeEeeT i++)
#define YeEEEeET *fw;
#define YeEeeeET fill_map(hashmap
#define YeeEEET cur
#define YEeEEeT hm_replace(hashmap
#define YeeeEeT hm_destroy(hashmap
#define YEEeEeEeT "%[^\"]s"
#define YEEEeeEeT buf[MAX_LINE];
#define YEEeEEeeT skip_to_code(fr);
#define yEeEEEeT free(res->res);
#define yeEEeET NULL;
#define yEeET *yeet
#define yeeET yeet_size++;
#define YEEEEeeeT extract_key_from_line(&cp,
#define yeEEEEET hm_print(map);
#define YEeEEEET "\nMAP:\n"
#define YeEeeEET "w"
#define yEEEeEeT map->table[hash]
#define yeeeeEeT val)
#define yEEeEeT *map,
#define YEeEEeEeT +=
#define YEeEEEeeT hm_get(map,
#define YEEEEeeT "]\n"
#define yEEeEET (cur->next)
#define yeeEEeT val);
#define yeEeEeT map);
#define YeEEeEeeT yeet);
#define YeeEeEeeT yeet
#define yeeEeeET *);
#define YEeEEEeT *del
#define YeEET *
#define yEEEEeEeT '\\')
#define yeEeEEeeT EXIT_SUCCESS;
#define YeeeEEeeT "+%li, cp -> %c\n"
#define YeeeeeeT +
#define yEeeEeT *map);
#define yEeeeeeeT fclose(fw);
#define yeeEEeeT ,
#define YeeEeeeT malloc(sizeof(node*)
#define yeeEeET *res
#define yEEEET V;
#define YEEEEeET write_file
#define YEeeET -
#define yEEeeEeeT "LINE: %s\n"
#define YeEeeEeeT "NOT FOUND COMMENT END\n"
#define yEeeeeEeT **line_pointer_pointer,
#define YeeeEeET argc,
#define yeeEEeEeT key
#define YEEeeeET FILE
#define YeEEEeeT cur->key,
#define yeeeeeeT 5)
#define YEEEeET place_in_table(map->table_size,
#define YEEEEEEeT f)
#define YeEeeEEeT "%[^\"\n ]s"
#define yEEeeeEeT switch
#define YeeeeeEeT "%s"
#define yEeEeeeT map->table_size
#define YeeEEEEeT ||
#define YeeeEEEeT return;
#define YeEEEeEeT 2)
#define YeeeEeeeT MAX_LINE,
#define yEeEEeeT map->table[i];
#define YEEEEeT long
#define YEEeeeeeT free(line);
#define YeeeEET map->table[hash];
#define yeeeEeeT printf(
#define yEeEEET 5381;
#define YeeeeeeeT fclose(fr);
#define YEeeEEeT res->res->val;
#define yeEEeEeT strcpy(new_node->val,
#define yeEEeeT hashmap;
#define YEEET capital;
#define YeEEeT yeet[i]
#define YeeEEeeeT &&
#define YEEeeEET "Cant open file: '%s' for writing\n"
#define YEEEeT 'Y'
#define yEeEeEEeT *fr)
#define YeEeeeeeT free(yeet);
#define yEEEEEEeT skip_to_code(FILE*
#define YEeeEeeeT line_length
#define YEeEeeeT map;
#define yeEeeeT val;
#define yeeeET :
#define Yeet char
#define yEEEEEeeT "line : %s\n"
#define yEeeeEET ;
#define YEeET (char*)
#define YeEEEEEeT fputs(buf,
#define YEEEeEeeT "ADDED"
#define yEEEeeeeT *fr,
#define YeeEeEET handle_includes_and_defines(fr,
#define YEeEeeET **,
#define YEeeT <
#define YeEeeeEeT '/')
#define yeeeeeeeT write_to_file_from_map(map,
#define YeEeEEET status
#define YeeT =
#define yEEt n++;
#define YEet n);
#define yeEeEeET >
#define yEET (bit
#define yeEeeeeeT (yeet)
#define yeeEeEET write_file);
#define yEeEeeET extract_key_from_line(char
#define YeeEEeT hm_remove(hashmap
#define yEEEeT ?
#define yEeeEEeeT strlen(key),
#define yEeeeET search_chain_res
#define yeEeeEeeT (!cp)
#define yEeEEeET (!fr)
#define yEeeEEeT val
#define yeEeEEEeT fw)
#define YEeeeeeT table_size)
#define yEeeeEeeT find_end_of_comment(&cp,
#define YeeeET 'y';
#define YeeeeEEeT strlen(buf)
#define yeEeEeeeT strlen(line);
#define YeEEeeT *hm_create();
#define YeeEeT 2;
#define YEeeEeEeT strcat(key,
#define yeeeEEeeT "FAILED"
#define yEEeEEeT &map->table[place_in_table(map->table_size,
#define YEeEEET c;
#define YeEeeET search_chain_res;
#define YeeeeET table_size,
#define yeeEeeT **table;
#define YEeeEEET MAX_LINE);
#define YeeEEeeT i);
#define YeEEeET res->res
#define yeeeT INT_MAX)
#define yeeT bit
#define yeEeeeEeT *line_pointer_pointer;
#define yEEeeET *search_chain(hashmap
#define yeeEeeEeT 1))
#define yEEeeeeeT (line)
#define YeEEeEET fseek(fr,
#define yEEeEeET "You need to pass a file name as an argument\n"
#define yeEeeET *res;
#define yeeEEeeeT '\0'
#define YeeeeT (int
#define yEEeT <<=
#define yeEEEeeT "'%s->%s' "
#define yEeeEeeT );
#define yEeEEEEeT isspace(c))
#define YeEEEET *key++)
#define YEeeEET res;
#define YeeeeeT K
#define yeEeEEET *line
#define YeeEEEeT (*root)->next;
#define yeeeEEeT map->size++;
#define YeEeEET cur;
#define yEEeET 't';
#define YeEeEeEeT sscanf(cp
#define yeeeeEeeT GO_TO_NEW_LINE)
#define YeeEEeET "r"
#define YEeEeET res->prev
#define yEeEET return
#define yeeeeT for
#define yEeeeeeET "%*[^\n]\n"
#define yEeEeeEeT '/':
#define YeeeeeET new_val)
#define yEeEeET malloc(sizeof(search_chain_res));
#define yEEET yeet_size);
#define yEEeeEEeT strlen(buf);
#define yeEEEeEeT strlen(key);
#define yEEeeeT node;
#define YeEEeEEeT strstr(line,
#define YeEeEEeeT add_defines(fw,
#define yeeeEeET main(int
#define yeeEEEeT *root
#define yeEEET typedef
#define YEeEeEET (ftell(fr)
#define YeeeeEeT search_chain(map,
#define yeEEEET (c
#define yeeeeET place_in_table(size_t
#define YEEt int
#define YEeeeeEeT *key)
#define YEEeEeeeT (*cp
#define yEeeEeeeT fr))
#define YeEeEEeT **root
#define YEeeeEeT free(res);
#define YeEeEeET 3)
#define yEEEeeeT hm_print(hashmap
#define yeEEEeT new_val);
#define YeeeeEeeT FIND_END_OF_COMMENT)
#define YeEeeEeT *new_node
#define yEeEeeT table_size;
#define yeeeeeT node
#define YeEEeeeeT *key,
#define yeEeEeeT (map->table[i]
#define YEEeeET key)
#define YeEEET K;
#define yeEEeT 0)
#define YeET while


Yeet  yEet  YEet 


Yeet   yEet   yeEt 
YeEt 
    yEEt 
    YEEt  yeeT  YeeT  yEeT 
    YEEt   YEeT  YeeT   yeET 
    YeET  yEET  YEET  yeeeT  YeEt  
        YeeeT  yEeeT  YEeeT  yeEeT  YeEeT 
        yeeT   yEEeT  YEEeT 
        yeeET 
    YeeET 
    
    Yeet    yEeET  YeeT    YEeET  yeEET  YeEET  yEEET 

    YEEt    YEEET 
    yeeeeT  YeeeeT  yEeeeT  YeeT     YEeeeT  yEeeeT   YEeeT   yeEeeT  YeEeeT  YeEt   
        yEEeeT  YeeT      YEEeeT  yeeEeT  YeeEeT          YeeeT   yEeEeT  YEeEeT  yeEEeT  YeEt    
            YeEEeT  YeeT       yEEeeT   yEEEeT  YEEEeT  yeeeET  YeeeET 
        YeeET   yEeeET  YeeeT    yEeEeT   YEeEeT   YEeT   YEeeET  yeEeET  YeEt     
            YeEEeT   YeeT        yEEeeT    yEEEeT   YeEeET  yeeeET   yEEeET 
        YeeET    yEeeET   YeEt      
            YeEEeT    YeeT         yEEeeT     yEEEeT    YEEeET  yeeeET    yeeEET 
        YeeET    

        YEEeeT   YeeEET  YEEeT  
    YeeET     

    yEeEET  YEeEET 
YeeET      




yeEEET  Yeet     YeEET   YeEEET 
yeEEET   Yeet      YeEET    yEEEET 

yeEEET    YEEEET  yeeeeeT 
YeEt       
    YeeeeeT  yEeeeeT 
    YEeeeeT  yeEeeeT 
    YEEEET   yeeeeeT   YeEeeeT 
YeeET        yEEeeeT 

yeEEET     YEEEET    YEEeeeT 
YeEt        
    yeeeeeT    yeeEeeT      YeeEeeT  yEeEeeT 
    YEEt     YEeEeeT 
YeeET         yeEEeeT 

YEEeeeT   YeEEeeT 
YEEeeeT    yEEEeeT  YEEEeeT 
yeeeEeT  YeeeEeT  yEeeEeT 
YEEt      YEeeEeT  yeEeEeT 

YEEt       YeEeEeT  yEEeEeT  YeeeeeT   YEEeEeT  YEeeeeT   yeeEEeT 
YEEt        YeeEEeT  yEEeEeT   YeeeeeT    yEeEEeT 
YEEt         YEeEEeT  yEEeEeT    YeeeeeT     YEEeEeT   YEeeeeT    yeEEEeT 
YEeeeeT     YeEEEeT  yEEeEeT     YeeeeeT      yEeEEeT  
yEEEEeT  YEEEEeT  yeeeeET  YeeeeET  YeeeeeT       yEeEEeT   




yeEEET      YEEEET     yEeeeET 
YeEt         
    yeeeeeT     YEeeeET 
    yeeeeeT      yeEeeET 
YeeET          YeEeeET 


yEeeeET   yEEeeET  yEEeEeT      YeeeeeT        YEEeeET 
YeEt          
    yEeeeET    yeeEeET  YeeT          YeeEeET  yEeEeET 
    YEeEeET  YeeT           yeEEeET 
    YeEEeET  YeeT            yeEEeET  

    YEEt          yEEEeET  YeeT             YEEEeET  yEeEEeT    
    yeeeeeT       yeeeEET  YeeT              YeeeEET 

    YeeeT     yEeeEET  YeEt                    yEeEET   YEeeEET 
    YeeET          

    YeeeT      yeEeEET  YEEeeET   YEeEeT    yeEEeT   YeEt            
        YeEEeET   YeeT               YeEeEET 
        yEeEET    YEeeEET  
    YeeET           

    YeET   yEEeEET  YeEt             
        YeeeT       YEEeEET  YEEeeET    YEeEeT     yeEEeT    YeEt              
            YEeEeET   YeeT                YeEeEET  
            YeEEeET    YeeT                 yeeEEET 
            yEeEET     YEeeEET   
        YeeET            
        YeeEEET  YeeT                  yeeEEET  
    YeeET             

    yEeEET      YEeeEET    
YeeET              


yEEEEeT   YEEEEeT   yeeeeET   YeeeeET   YeeeeeT         YEEeeET    
YeEt               
        yEEEEeT    YEEEEeT    yEEEeET   YeeT                   yEeEEET 
        YEEt           YEeEEET 

        YeET    yeEEEET  YeeT                    YeEEEET 
            yEEEeET    YeeT                     yEEEEET  YEEEEET  yeeeeeeT  YeeeeeeT  yEeeeeeT  YeeeeeeT   YEeEEET   

        yEeEET       yEEEeET     yeeEeT   yEeEeeT  
YeeET               

YEEeeeT     yEEEeeT   YEeeeeeT 
YeEt                
    YEEeeeT      yeEeeeeT  YeeT                      YeEeeeeT  yEEeeeeT 
    YEEeeeeT  YeeT                       yeeEeeeT  YeeEeeeT  YeEET     YEEEeeT  
    yEeEeeeT  YeeT                        yEeEeeT   
    yEeEET        YEeEeeeT 
YeeET                

yeeeEeT   YeeeEeT   yeEEeeeT 
YeEt                 
        YeEEeeeT 
YeeET                 

YEEt            yEEEeeeT  yeEEeeeT  
YeEt                  
    YeeeT        YEEEeeeT 
    YeEt                   
        yeeeEeeT YeeeEeeT yEeeEeeT 
        yEeEET         YEeeeT  
    YeeET                  

    yeeeeT   YeeeeT   yEeeeT    YeeT                         YEeeeT    yEeeeT     YEeeT    YEeeEeeT  YeEeeT  
    YeEt                    
        YeeeT         yeEeEeeT  YeEeEeeT  yEEeEeeT 
        YeEt                     
            yeeeEeeT  YEEeEeeT yeeEEeeT  YeeEEeeT       
            yeeeeeT        yeeeEET   YeeT                          yEeEEeeT 
            YeET     YEeEEeeT 
            YeEt                      
                yeeeEeeT   yeEEEeeT yeeEEeeT   YeEEEeeT  yEEEEeeT 
                YeeEEET   YeeT                           yeeEEET   
            YeeET                   
            yeeeEeeT    YEEEEeeT yEeeEeeT  
        YeeET                    
    YeeET                     

    yEeEET          YEEeT   
YeeET                      

YEEt             YeEeEeT   yEEeEeT       YeeeeeT          YEEeEeT    YEeeeeT      yeeeeEeT 
YeEt                       
    YeeeT          YEEEeeeT  
    YeEt                        
        yeeeEeeT     YeeeEeeT  yEeeEeeT   
        yEeEET           YEeeeT    
    YeeET                       

    yEeeeET     yeeEeET   YeeT                            YeeeeEeT  yEeEEeT      
    YEEt              yEeeeEeT  YeeT                             YeEEeET     YeEeEeeT   yeEEeET   
    YEeeeEeT 
    YeeeT           yeEeeEeT  YeEt                         
        yEeEET            YEeeeT     
    YeeET                        

    YEEt               yEEEeET      YeeT                              YEEEeET   yEeEEeT      

    yeeeeeT         YeEeeEeT  YeeT                               yEEeeEeT  YEEeeEeT 
    yeeEeEeT  YeeT                                YEeET   yeEET   YeEET      YeeEeEeT 
    yEeEeEeT  YeeT                                 YEeET    yeEET    YeEET       YeeEeEeT  

    YEeEeEeT  yEeEEeT       
    yeEEeEeT  yeeEEeT  

    YeEEeEeT  YeeT                                  YeeeEET  
    yEEEeEeT  YeeT                                   YEEEeEeT 

    yeeeEEeT 

    yEeEET             YEEeT    
YeeET                         

YEeeeeT       YeEEEeT   yEEeEeT        YeeeeeT           YEEeeET     
YeEt                          
    YeeeT            YEEEeeeT    YeEt                           
        yeeeEeeT      YeeeEeeT   yEeeEeeT    
        yEeEET              YEeeeT      
    YeeET                          
    
    yEeeeET      yeeEeET    YeeT                                    YeeeeEeT   yEeEEeT        

    YeeeT             YeeeEEeT  YeEt                            
        YEeeeEeT  
        yEeEET               yeEEeET    
    YeeET                           
    
    YEeeeeT        yEeeEEeT  YeeT                                     YEeeEEeT 
    YEeeeEeT   
    yEeEET                yeEeeeT  
YeeET                            

YEEt                YeeEEeT   yEEeEeT         YeeeeeT            YEEeeET      
YeEt                             
    YeeeT              YEEEeeeT     YeEt                              
        yeeeEeeT       YeeeEeeT    yEeeEeeT     
        yEeEET                 YEeeeT       
    YeeET                             

    yEeeeET       yeeEeET     YeeT                                      YeeeeEeT    yEeEEeT         

    YeeeT               YeeeEEeT   YeEt                               
        yEeEET                  YEeeeT        
    YeeET                              

        YeeeT                yeEeEEeT  YeEt                                
        yeeeeeT          YeEeEEeT  YeeT                                       yEEeEEeT  YEEeEEeT 
        yeeEEEeT  YeeT                                        YeeEEEeT 
        yEeEEEeT 
    YeeET                                yEeeET    YeEt                                 
        yeeeeeT           YEeEEEeT  YeeT                                         yeEEEEeT 
        YeEEEEeT  YeeT                                          yEEEEEeT 
        YEEEEEeT 
    YeeET                                

    yeeeeeET 

    yEeEET                   YEeeeT         
YeeET                                 

YEEt                 YEeEEeT   yEEeEeT          YeeeeeT             YEEeEeT     YEeeeeT         YeeeeeET 
YeEt                                  
    YeeeT                 YEEEeeeT      YeEt                                   
        yeeeEeeT        YeeeEeeT     yEeeEeeT      
        yEeEET                    YEeeeT          
    YeeET                                  

    yEeeeET        yeeEeET      YeeT                                           YeeeeEeT     yEeEEeT          

    YeeeT                  YeeeEEeT    YeEt                                    
        yEeEET                     YEeeeT           
    YeeET                                   

    yEeeeeET  YeeT                                            YEeeeeET 

    yEeEET                      YEEeT     
YeeET                                    

YEEt                  yeEeeeET  YeeT                                             YEEeT      

YEEt                   YeEeeeET  yEEeeeET  Yeet       yEEeeeET   Yeet        yEEeeeET    Yeet         yEEeeeET     YEEeeeET  yEEeeeET      YEEeeeET   yeeEeeET 
YEEt                    YeeEeeET  yEEeeeET       Yeet          yEEeeeET        Yeet           yEEeeeET         Yeet            yEEeeeET          YEEeeeET    yEEeeeET           YEEeeeET     yeeEeeET  
YEEt                     yEeEeeET  YEeEeeET  Yeet             yeeEeeET   
yeeeEeT    yeEEeeET  YEeEeeET   Yeet              yEEeeeET            YEEeeeET      yeeEeeET    
YEEt                      YeEEeeET  yeeEeeET     
yeeeEeT     yEEEeeET  yEEeeeET             YEEeeeT       yeeEeeET      
YEEt                       YEEEeeET  yEEeeeET              YEEeeeET       yeeEeeET       

YEEt                        yeeeEeET  YeeeEeET  Yeet               yEeeEeET 
YeEt                                     
    YeeeT                   YEeeEeET  yeEeEeET  YeEeEeET  YeEt                                      
                yeeeEeeT         yEEeEeET yEeeEeeT       
        yEeEET                       YEEeT       
    YeeET                                     

    
    YEEeeeET        YEEeEeET  YeeT                                              yeeEEeET  YeeEEeET yEeeEeeT        
    YeeeT                    yEeEEeET  YeEt                                       
                yeeeEeeT          YEeEEeET yeeEEeeT    yeEEEeET 
        yEeEET                        YEEeT        
    YeeET                                      

    YEEeeeET         YeEEEeET 
    Yeet                yEEEEeET 
    YeeeT                     YEeeEeET   YEeEeT      YeEeEeET   YeEt                                        
        YEEEEeET  YeeT                                               yeeeeEET 
    YeeET                                        yEeeET     YeEt                                         
        YEEEEeET   YeeT                                                YeeeeEET yEeeeEET 
    YeeET                                        

    YEeeeEET  YeeT                                                 yeEeeEET  YeEeeEET yEeeEeeT         
    YeeeT                      yEEeeEET  YeEt                                          
        yeeeEeeT           YEEeeEET yeeEEeeT     yeeEeEET 
        yEeEET                         YEEeT         
    YeeET                                         

    YeeEeEET  yEeEeEET 
    
    YeeeT                       YEeEeEET  YEeEeT       yeEEeT     YeEt                                           
        yeeeEeeT            yeEEeEET yEeeEeeT          
        yEeEET                          YEeeeT            
    YeeET                                          

    YeEEeEET  yEEEeEET  YEEEeEET 

    
    YEEeeeT        yeEeeeeT   YeeT                                                  yeeeEEET 

    Yeet                 YeeeEEET                                                  Yeet                  yEeeEEET  YeeT                                                   YEeET     yeEET     YeEET        YEeeEEET         Yeet                   yeEeEEET  YeeT                                                    YEeET      yeEET      YeEET         YEeeEEET     

    YEEt                         YeEeEEET  YeeT                                                     yEEeEEET  YEEeEEET  yeeEEEET  YEEeEeT      YeeEEEET  yEeEeEET  
    YeeeT                        yEeEEEET  YeEt                                            
        yeeeEeeT             YEeEEEET yEeeEeeT           
        yeEEEEET 
        yeeeEeeT              YeEEEEET yEeeEeeT            
    YeeET                                           

    YeeeT                         yEEEEEET  YEeEeT        YEEEEEET  YeEt                                             
        YeEeEEET   YeeT                                                      yeeeeeeeT  YEEeEEET   yeeEEEET   YEEeEeT       YeeEEEET   yEeEeEET   
    YeeET                                            

    
    YeeeeeeeT 
    yEeeeeeeT 

    YEeeeeeeT 

    YeeeT                          yeEeeeeeT  YeEeeeeeT 
    YeeeT                           yEEeeeeeT  YEEeeeeeT 
    YeeeT                            yeeEeeeeT   YeeEeeeeT 
    
    yEeEET                           yEeEeeeeT 
YeeET                                             

YEEt                          YeEeeeET   yEEeEeT           Yeet                    YEeEeeeeT  Yeet                     yeEEeeeeT  Yeet                      YeEEeeeeT  YEEeeeET          yEEEeeeeT  YEEeeeET           YEEEeeeeT 
YeEt                                              
    YeET      yeeeEeeeT  YeeeEeeeT  yEeeEeeeT  YeEt                                               
        YEEt                           YEeeEeeeT  YeeT                                                       yeEeEeeeT 

        Yeet                       YeEeEeeeT  YeeT                                                        yEEeEeeeT          YeET       YEEeEeeeT  YeEeEeeT    yeeEEeeeT  YeeEEeeeT   yEeEEeeeT  YEeEEeeeT  YeEt                                                
            YeeeT                             yeEEEeeeT  YeEt                                                 
                YeEEEeeeT 
                yEEEEeeeT 
            YeeET                                              
            
            YEEt                            YeEeEEET    YeeT                                                         YEEEEeeeT  yEeEEeT           

            YeeeT                              yEEEEEET   YEeEeT         yeeeeEeeT  YeEt                                                  
                YeEeT  
            YeeET                                               

            YeeeT                               yEEEEEET    YEeEeT          YeeeeEeeT  YeEt                                                   
                yEeeeEeeT  YEEeEEET    YEeeeEeeT 
                YeeeT                                yeEeeEeeT  YeEt                                                    
                    yeeeEeeT               YeEeeEeeT yEeeEeeT             
                    yeeeEeeT                yEEeeEeeT yeeEEeeT      YEEeeEeeT 
                    yEeEET                            yeeEeEeeT 
                YeeET                                                

                yEEEEeeeT  
            YeeET                                                 

            YeeEeEeeT  YeeT                                                          yEeEeEeeT 
            YEEt                             YEeEeEeeT  YeeT                                                           yeEEeEeeT  YEEeEeT        YeEEeEeeT 

            YeeeT                                 yEeEEEET   YeEt                                                     
                yeeeEeeT                 yEEEeEeeT yeeEEeeT       YEeEeEeeT   yEEEeT     YEEEeEeeT  yeeeET     yeeeEEeeT yeeEEeeT        YEEeEeT         YeEEeEeeT  
                yeeeEeeT                  YeeeEEeeT yeeEEeeT         yEeeEEeeT  YEeeEEeeT 
            YeeET                                                  
        YeeET                                                   
    YeeET                                                    

    yEeEET                             yeEeEEeeT 
YeeET                                                     

YEEt                              YeeEeeET   yEEeEeT            Yeet                        YEeEeeeeT   Yeet                         yeEEeeeeT   Yeet                          YeEEeeeeT   YEEeeeET            yEEEeeeeT   YEEeeeET             YEEEeeeeT  
YeEt                                                      
    YeEeEEeeT  yeEeEeT  

    yEEeEEeeT 
    YEEeEEeeT 

    yeeEEEeeT  YeEEEEET  yEeeEeeT              

    YeET        yeeeEeeeT   YeeeEeeeT   yEeeEeeeT   YeEt                                                       
        YEEt                               YEeeEeeeT   YeeT                                                            yeEeEeeeT  

        Yeet                           YeEeEeeeT   YeeT                                                             yEEeEeeeT           YeET         YEEeEeeeT   YeEeEeeT     yeeEEeeeT   YeeEEeeeT    yEeEEeeeT   YEeEEeeeT   YeEt                                                        
            YeeeT                                  yeEEEeeeT   YeEt                                                         
                yeeEEEeeT   YeeEEEeeT yeeEEeeT          YEeeEEeeT  
                YeEEEeeeT  
                yEEEEeeeT   
            YeeET                                                      

            YEEt                                YeEeEEET     YeeT                                                              YEEEEeeeT   yEeEEeT            

            YeeeT                                   yEEEEEET     YEeEeT           yeeeeEeeT   YeEt                                                          
                YeEeT   
            YeeET                                                       

            YeeeT                                    yEEEEEET      YEeEeT            YeeeeEeeT   YeEt                                                           
                yEeeeEeeT   YEEeEEET     YEeeeEeeT  
                YeeeT                                     yeEeeEeeT   YeEt                                                            
                    yeeeEeeT                   YeEeeEeeT  yEeeEeeT               
                    yeeeEeeT                    yEEeeEeeT  yeeEEeeT           YEEeeEeeT  
                    yEeEET                              yeeEeEeeT  
                YeeET                                                        

                yEEEEeeeT    
            YeeET                                                         

            YeeeT                                      yEeEEEET    YeEt                                                             
                yeeeEeeT                     yEeEEEeeT yeeEEeeT            yEeEEeT             
            YeeET                                                          

            YeeEeEeeT   YeeT                                                               YEeEEEeeT  yEeEEeT              

            YeeeT                                       yeEEEEeeT  YeEt                                                              
                yeeeEeeT                      YeEEEEeeT yeeEEeeT             yEeEEeT               
                yeeeEeeT                       yEEEEEeeT yeeEEeeT              YEEeeEeeT   
                yEeEET                               yeeEeEeeT   
            YeeET                                                           

            YEEEEEeeT  yeeeeeEeT yEeeEeeT                
            yeeEEEeeT    YeeeeeEeT yeeEEeeT               YeEEeEeeT   
        YeeET                                                            
    YeeET                                                             

    yEeEET                                yeEeEEeeT  
YeeET                                                              


YEEt                                 yEeEeeET   yEeeeeEeT  Yeet                            YEeeeeEeT  YeEt                                                               
    Yeet                             YeEeEeeeT    YeeT                                                                yeEeeeEeT 

        YeeeT                                        YEEeEeeeT    YEeEeT             YeEeeeEeT  YeEt                                                                                                   yEEeeeEeT  YEEeeeEeT  YeeeeeeT    yeeEeeEeT 
        YeEt                                                                 
            YeeEeeEeT  yEeEeeEeT  yEeEET                                 YEeEeeEeT 
            YeeEeeEeT   yeEEeeEeT  yEeEET                                  YeEEeeEeT 

            yEEEeeEeT  YeEeT    
        YeeET                                                               
    YeeET                                                                

    Yeet                              YEEEeeEeT 
    yeeeEeEeT  YeeeEeEeT yEeeEeeT                 

    YeeeT                                         YEEeEeeeT     YEeEeT              yEeeEeEeT  YeEt                                                                                                    YEeeEeEeT  yeEeEeEeT yEeeEeeT                  
        YeEeEeEeT  YeeeeeeT     yEEeEeEeT  YEEeEeEeT yeeEEeeT                yeeEEeEeT  YeeeeeeT      YeeEEeEeT 
        YEeeEeEeT   yeEeEeEeT  yEeeEeeT                   
        yEeEEeEeT  YEeEEeEeT  yeEEEeEeT 

        YeET          YEEeeeEeT   YEeeET   YeEEEeEeT  YEeEeT               yEEEEeEeT  YeEt                                                                                            YeeeT                                          YEEeEeeeT      YEeEeT                yEeeEeEeT   YeEt                                                                    
                YEeeEeEeT    yeEeEeEeT   yEeeEeeT                    
                YeEEEeeeT   
                yEEEEeeeT     
            YeeET                                                                  yEeeET      YeEt                                                                     
                YEEEEeEeT  YEEeEeEeT  yeeEEeeT                 yeeeeEEeT 
                YEeeEeEeT     yeeeeEEeT  
                YEeeEeEeT      yeEeEeEeT    yEeeEeeT                     
                yEeEEeEeT   YEeEEeEeT   YeeeeEEeT  YeeeeeeT       YEEeT          
            YeeET                                                                  
        YeeET                                                                   
    YeeET                                                                     yEeeET       YeEt                                                                                                                  YEEEEeEeT   yEeeeEEeT yeeEEeeT                  yEeEEeT                
        yEeEEeEeT    YEeEEeEeT    yeEEEeEeT  

        YeeeT                                           YEEeEeeeT       YEeEeT                 YEeeeEEeT  YeeEEeeeT    yeEeeEEeT  YEeeET    yeEeET   YEeEeT                  yEEEEeEeT   YeEt                                                                                    YEeeEeEeT       yeEeEeEeT     yEeeEeeT                      
            YeEEEeeeT    
            YEEEEeEeT    YeEeeEEeT yeeEEeeT                   yeeeeEEeT   
            YEeeEeEeT        yeeeeEEeT    
            yEeEEeEeT     YEeEEeEeT     yEEeeEEeT 
        YeeET                                                                     
    YeeET                                                                      

    YEEeeEEeT  YeeT                                                                 yeeEeEEeT 

    yEeEET                                   YEeeeT             
YeeET                                                                       


yeeeEeT      yeEEeeET   YeeEeEEeT  Yeet                               YEeEeeeeT    YEEeeeET              yEeEeEEeT 
YeEt                                                                        
    Yeet                                YeEeEeeeT     YeeT                                                                  YEeEeEEeT 
    YEEt                                  yeEEeEEeT  YeeT                                                                   YEeeeT              

    yEeEEeEeT      YeeT                                                                    YeEEeEEeT  yEEEeEEeT yEeeEeeT                       
    YeeeT                                            YEEEeEEeT  YeEt                                                                         
        yeeeEEEeT  YeeT                                                                     yEeEEeEeT       YeeeeeeT        YeeEeT  
        YeeeEEEeT 
    YeeET                                                                        
    
    YeET           yeeeEeeeT    YeeeEeeeT    yEeeEeeeT    YeEt                                                                          
        yEeEEeEeT        YeeT                                                                      YeEEeEEeT   yEEEeEEeT  yEeeEeeT                        
        YeeeT                                             YEEEeEEeT   YeEt                                                                           
            yeeeEEEeT   YeeT                                                                       yEeEEeEeT         YeeeeeeT         YeeEeT   
            YeeeEEEeT  
        YeeET                                                                         
    YeeET                                                                          

    yeeeEEEeT    YeeT                                                                        yeEEeET     
YeeET                                                                           

YEEt                                   yEeeEEEeT  YeeEEEET    YEeeEEEeT  yeEeEEEeT 
YeEt                                                                            
    Yeet                                 YEEEeeEeT  
    YeET            YeEeEEEeT  YeEt                                                                             
        Yeet                                  yEEeEEEeT  YeeT                                                                         YEEeEEEeT 
        YeeeT                                              yeEEEET   YEeEeT                   YEeEEeeeT    YeEt                                                                              
            yEeEET                                    YEeeeT               
        YeeET                                                                             yEeeET        YeeeT                                               yeEEEET    YEeEeT                    yeeEEEEeT  YeeEEEEeT  yEeEEEEeT  YeEt                                                                               
            YEeEEEEeT  YEeeeEeeT                              yeEEEEEeT  YeeeEeeeT     YEeeeEeeT                    YeEEEEEeT  yEeEeEET                          YeeET                                                                              yEeeET         YeEt                                                                                
            yEeEET                                     YEEeT           
        YeeET                                                                              
    YeeET                                                                               
YeeET                                                                                

YEEt                                    yEEEEEEeT  YEEEEEEeT 
YeEt                                                                                 
    YeET             YeEeEEEeT   YeEt                                                                                  
        Yeet                                   yEEeEEEeT   YeeT                                                                          yeeeeeeET 
        YeeeT                                                yeEEEET     YEeEeT                     YEeEEeeeT     YeEt                                                                                   
            yEeEET                                      YEeeeT                
        YeeET                                                                                  yEeeET          YeeeT                                                 yeEEEET      YEeEeT                      yeeEEEEeT   YeeEEEEeT   yEeEEEEeT   YeEt                                                                                    
            YeeeeeeET  yEeeeeeET yEeeEeeT                            
        YeeET                                                                                   yEeeET           YeEt                                                                                     
            YEeEEEEeT   YEeeeeeET 
            yEeEET                                       YEEeT            
        YeeET                                                                                   
    YeeET                                                                                    
YeeET                                                                                     

yeeeEeT       yEEEeeET   yeEeeeeET  YEEeeeT         yeEEeeeT   
YeEt                                                                                      
    yeeeeT    YeeeeT    yEeeeT      YeeT                                                                           YEeeeT                  yEeeeT       YEeeT     YEeeEeeT   YeEeeT    YeEt                                                                                       
        yeeeeeT            yeeeEET    YeeT                                                                            yEeEEeeT  
        YeET              YEeEEeeT   YeEt                                                                                        
            YeEeeeeET  yEEeeeeET yeeEEeeT                    YEEeeeeET  yeeEeeeET       
            YeeEEET    YeeT                                                                             yeeEEET    
        YeeET                                                                                       
    YeeET                                                                                       
YeeET                                                                                        
