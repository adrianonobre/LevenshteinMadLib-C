struct str_list {
    char **data;
    int capacity;
    int last_idx;
};

void init(struct str_list *p_list, int initial_capacity);
void add_str(struct str_list *p_list, char *str);
char *get_str(struct str_list *p_list, int pos);
void change_str(struct str_list *p_list, int pos, char *new_str);
int size(struct str_list *p_list);
void free_list(struct str_list *p_list);
