typedef struct {
    char **data;
    int capacity;
    int last_idx;
} str_list;

void init(str_list *p_list, int initial_capacity);
void add_str(str_list *p_list, char *str);
char *get_str(str_list *p_list, int pos);
void change_str(str_list *p_list, int pos, char *new_str);
int size(str_list *p_list);
void free_list(str_list *p_list);
