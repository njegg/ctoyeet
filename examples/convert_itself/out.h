#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <limits.h>
#include <stdarg.h>
#include <ctype.h>
     

#define MAX_LINE 256
#define SINGLE_LINE_COMMENT 1
#define MULTILINE_COMMENT 2

#define PUNCTS "(),;[]"
#define SSCANF_NON_STRING_FORMAT "%[^]\n\"()\[,; ]s"
#define SSCANF_STRING_FORMAT "%[^\"]s"

#define YeeeEeEet FILE*
#define YeeeeeEEt strchr
#define YEEeEEeT !cp
#define YEEeEt V
#define YeeeeEEET SSCANF_NON_STRING_FORMAT
#define YeEeet i--
#define YEEEeEet "\n"
#define YeeEEeet del
#define YEEEEET strlen
#define YEEEEeT back
#define YEeeEEEt "Error while opening files: %s\n"
#define YeeEEEEt head->key
#define YeEEeet !map
#define YEEeeeET *cp
#define YeEEEeeT "out.c"
#define YeEeEEeT **
#define YeEeeEEt *fr
#define YeeEEeeT map->size--
#define YeeeEeEt new_node->next
#define YEEeeEt calloc
#define YEeeEEt res
#define YEeeEet map->table
#define Yeeeet [
#define YeeeEEEeT "#define %s %s\n"
#define YeeeEeEEt '#'
#define YEeeeET *cur
#define YEeeEt 'T'
#define YeeeeT ]
#define YEeEeEEt -1
#define YeEeEeet *fw
#define YeeEeEet ->next
#define Yeeeeeet isspace
#define YEeeeeT hash
#define YEeEEt >>=
#define YEeEeEeT fseek
#define YEeEeEet "File is empty\n"
#define YEeeEEET strerror
#define YeeeeeEt back+1
#define YEeEEET <<
#define YeEEeeT printf
#define YeeEeeT void
#define YEEEeeEt added
#define YeEeEeeT *fw_h
#define YeeeT <=
#define YeeeeEeet punct
#define YEEEEEeT " "
#define YEeeeEet fopen_errno
#define YEEeEEEt "Not found comment end\n"
#define YEeEEeT c
#define YeeEeet *hm_create
#define YeeeeeT **table
#define YEeeEEeT fw_h
#define YeeEEEet !head
#define YeeeEEeeT f
#define YeeeEEeet fputs
#define YeeeeEet free
#define YeeEeEt hm_destroy
#define YEeeet 'y'
#define YeeeEEeT !res->res
#define YeeeeEEt new_node->key
#define YEeEet 'E'
#define YeeeEeEeT fgetc
#define YEEEEeet "READ: %s\n"
#define YEEeEEet MULTILINE_COMMENT
#define YeeEeEEt res->prev->next
#define YeeeeEeEt "\""
#define YEEEEEET *token_start
#define YEeEEeEt MAX_LINE
#define YeeEeT i
#define YEEEeeet generate_yeet
#define YeeEEEET head->val
#define YEEeeEeT EOF
#define YEeEeeET ftell
#define YEeEeeeT fprintf
#define YeEeeeEt fill_map
#define YEeEeet cur->key
#define YeEeET if
#define YEeEEeeT 101
#define YEeeeeet EXIT_FAILURE
#define YeEeEeET **token_start
#define YeEeeET new_val
#define YEeeeT else
#define YeEeeeeT DEBUG_INFO
#define YeeEEEeT head->next
#define yEEt n
#define YeeeeEEEt '\\'
#define YeeT n++
#define YeeEEeET *head
#define YEeEt char*
#define YeEeEEt hash_table_index
#define YEEEEEt s
#define YEEeEEt !=
#define YeeeeEeeT '\"'
#define YeEeeeet head
#define YeeeeEeET sscanf
#define YeeeEeeEt "*/"
#define YEeeeet !check_map_created
#define YEEeeeEt fgets
#define YeeeEeet new_node->val
#define YEEeEeT i++
#define YeeEeET *map
#define YeeeeeEeT ""
#define YeeeeeeET '*'
#define YeeeEEEt res->res->val
#define YeeEt INT_MAX
#define YeeeeeeEt cp
#define YEeeeEEt fr
#define YeEEeEeT EXIT_SUCCESS
#define YeeeEeET new_node
#define YeeEEet hm_print
#define YeeeEEet map->size++
#define Yeeeeet hashmap
#define YeeeET capital
#define Yeet {
#define YEEeEeEt SINGLE_LINE_COMMENT
#define YeeeEeeet **cpp
#define YEEEeeT cur->val
#define YEeet }
#define YEeEEEEt all_good
#define YEEeEET "%i -> [ "
#define yEet unsigned
#define YEEEEeeT !yeet
#define YEEEeEeT "%c"
#define YEeeEeET fw
#define YeEEeEt "Map may not be created. Use hm_create(size_t table_size).\n"
#define YeeeEeeET *cpp
#define YeeeEEt *prev
#define YeEET yeet_size++
#define YeEeeeT hm_remove
#define YeeeeEt size_t
#define YEeET malloc
#define YeeeEeeeT strstr
#define YeEEet ==
#define YEeEeEt cur->next
#define YEeT 16
#define YEEEEeEt "NOT IN MAP: '%s'\n"
#define YeEeEEEt skip_to_code
#define YeeeeeeT *--back
#define YEEeeeet stderr
#define YeEeEET check_map_created
#define YEEeET struct
#define YEeeeEeT !
#define YeeEEeEt free_chain
#define YEeeeEET fopen
#define YeeeeeEET PUNCTS
#define YeeeEEeEt fscanf
#define YeeEEeT hashmap*
#define YEEt yeet_size
#define YEEeeEet *cp!=
#define YeEeeT %
#define YEEet sizeof
#define YeeeeeET search_chain
#define YEeEeeT cur
#define YEeeET 't'
#define YeeeEet size
#define YEeeT *yeet
#define YEeEEeet hm_create
#define YEeeEEet "w"
#define YeEEEEET "ERROR: Output file name must be a '.c' file\n"
#define YeEeEeEt extract_token_from_line
#define yeET (
#define YeeeeEEeT +=
#define YEEEeeET rewind
#define YEEEeEt "]\n"
#define yEET )
#define YEeeeeEt strncpy
#define YeeEeEeT *del
#define YeEEeET *search_chain
#define YEEET yeet
#define YEEeT *
#define YEEeeeT node**
#define YeEEEEt NULL
#define YEEEt +
#define YeEeeet ,
#define YeeeEET *res
#define YEEeEEET "Line: %s\n"
#define YeEEeEET write_file
#define YeeEEt -
#define YEEEeEET "LINE: %s\n"
#define YEEEeEEt "NOT FOUND COMMENT END\n"
#define YEeeeeET 'h'
#define YeeEeeEt &map->table
#define YEeeEET strcmp
#define YeeeeeEet buf
#define YeEeeEeT FILE
#define YEEEeT key
#define YEeEeT 'e'
#define YeeEET 0
#define YeeeEEEet *f
#define YEEEEEEt "%s"
#define YEEeeEEt cp++
#define YEeeeEt map->table_size
#define YeEEt 1
#define YEEEeeeT map->size
#define YEeeEeeT errno
#define YeEEEEeT ||
#define YeEeEeT long
#define YeEeEt 2
#define YeEEEEet 3
#define YEeEEEeT token
#define YeEEEet search_chain_res*
#define YEET 4
#define YeEEEeET write_file_len
#define YEEeeet 5
#define YeEeEet hm_get
#define YeeeeEEet SSCANF_STRING_FORMAT
#define YeEeeEet *token
#define YeeeEeeT strcpy
#define YeEeeEET write_to_file_from_map
#define YeeEeeet !res->prev
#define YeeET &&
#define YeEEEt 'Y'
#define YEeEeeet fclose
#define YEeEeET cur->next->key
#define YEeEEEET !all_good
#define YEeeEeEt !fopen_errno
#define YeEEET :
#define yeeT char
#define YEEEEEet strcat
#define YEeEEeET fill_map_ok
#define YeEEeeEt argc
#define YeEt ;
#define YEEeeEET continue
#define YEEeEet <
#define YEEeEeet status
#define YEEeeeeT "Something went wrong"
#define YeEEEeEt "outout.c"
#define YEet =
#define YEEEEet *s
#define YEEeeET node*
#define YEeeEeT !cur
#define YeEet >=
#define YEeEEEt *key++
#define YeEEeT ?
#define YeeeEeT search_chain_res
#define YEEEEeET "LINE : %s\n"
#define YeeEeEET res->res->next
#define YeeEEEt map
#define YEEEEt val
#define YEEeEeET break
#define YEEEET *next
#define YeeeeeeeT next
#define YeEEeEet "Usage:\n$ yeet input.c [output.c]"
#define YeEEeeet handle_includes_and_defines
#define YeEEEET res->res
#define YeET bit
#define YEeEeEET SEEK_CUR
#define YEeeeeeT write_file_h
#define YeeeEt '\0'
#define YeEeT <<=
#define YeEEeeET **args
#define YeEeEEET add_defines
#define YEEEeet "'%s->%s' "
#define YEeEEet 5381
#define YeEEEeet args
#define YEEeeT K
#define YeEeeeET *line
#define YEEeEeeT &cp
#define YEeeEeet "r"
#define YeeeEEET rtrim
#define YeEEEeT res->prev
#define YeEeeEt hm_replace
#define YEeEET return
#define YeeEet for
#define YeeeEEeET "%*[^\n]\n"
#define YeEEeEEt *write_file
#define YeeeEeEET ungetc
#define YEeEEEet line
#define YEEEeET *rtrim
#define YeEEeeeT main
#define YeeEeeET *root
#define YeeEEET hm_put
#define YEEeet typedef
#define YeeeeEET 128
#define yEeT int
#define YEeEeeEt "#include \"%s\""
#define YeeEeeeT **root
#define YeEEEEEt 'c'
#define Yeeeeeeet '/'
#define YeEeEEet find_end_of_comment
#define YeeeeEeT *new_node
#define YeeeeET table_size
#define YEEEet node
#define yeEt *generate_yeet
#define Yeeet while
