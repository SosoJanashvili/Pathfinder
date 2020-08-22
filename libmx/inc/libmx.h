#ifndef LIBMX_LIBMX_H
#define LIBMX_LIBMX_H

#include <unistd.h>
#include <wchar.h>
#include <stdbool.h>
#include <stdlib.h>
//#include <malloc/malloc.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
}           t_list;

/*  Utils pack  */
void mx_printchar(char c);                                                  //100
void mx_print_unicode(wchar_t c);                                           //100
void mx_printstr(const char *s);                                            //100
bool mx_isspace(char c);
bool mx_isdigit(char c);
bool mx_isalpha(int c);
void mx_print_strarr(char **arr, const char *delim);                        //16      edited
void mx_printint(int n);                                                    //100
double mx_pow(double n, unsigned int pow);                                  //100
int mx_sqrt(int x);                                                         //100
char *mx_nbr_to_hex(unsigned long nbr);                                     //95      edited
unsigned long mx_hex_to_nbr(const char *hex);                               //100
int mx_atoi(const char *str);
char *mx_itoa(int number);                                                  //100
void mx_foreach(int *arr, int size, void (*f)(int));                        //100
int mx_binary_search(char **arr, int size, const char *s, int *count);      //100
int mx_bubble_sort(char **arr, int size);                                   //100
//int mx_quicksort(char **arr, int left, int right);
void mx_swap_arr_elements(char **s1, char **s2);

/*  String pack  */
int mx_strlen(const char *s);                                               //100
void mx_swap_char(char *s1, char *s2);                                      //100
void mx_str_reverse(char *s);                                               //100
void mx_strdel(char **str);                                                 //100
void mx_del_strarr(char ***arr);                                            //100
int mx_get_char_index(const char *str, char c);                             //100
char *mx_strdup(const char *s1);                                            //100
char *mx_strndup(const char *s1, size_t n);                                 //52  edited
char *mx_strcpy(char *dst, const char *src);                                //100
char *mx_strncpy(char *dst, const char *src, int len);                      //100
int mx_strcmp(const char *s1, const char *s2);                              //100
int mx_strncmp(const char *s1, const char *s2, int len);
char *mx_strcat(char *restrict s1, const char *restrict s2);                //100
char *mx_strchr(const char *s, int c);
char *mx_strstr(const char *haystack, const char *needle);                      //30 edited
int mx_get_substr_index(const char *str, const char *sub);                      //100
int mx_count_substr(const char *str, const char *sub);                          //100
int mx_count_words(const char *str, char c);                                    //100
char *mx_strnew(const int size);                                                //100
char *mx_strtrim(const char *str);                                              //55   edited
char *mx_del_extra_spaces(const char *str);                                     //0    edited
char **mx_strsplit(char const *s, char c);                                      //100
char *mx_strjoin(char const *s1, char const *s2);                               //100
char *mx_file_to_str(const char *file);                                         //60
int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd);
//char *mx_replace_substr(const char *str, const char *sub, const char *replace);
char *mx_strsub(char const *s, unsigned int start, size_t len);
void mx_printerror(const char *s);

/*  Memory pack  */
void *mx_memset(void *b, int c, size_t len);                                    //100
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);        //100
void *mx_memccpy(void *restrict dst, const void *restrict src,
                int c, size_t n);                                               //100
int mx_memcmp(const void *s1, const void *s2, size_t n);                        //100
void *mx_memchr(const void *s, int c, size_t n);                                //100
void *mx_memrchr(const void *s, int c, size_t n);                               //100
void *mx_memmem(const void *big, size_t big_len, const void *little,
                size_t little_len);                                             //80   edited
void *mx_memmove(void *dst, const void *src, size_t len);                       //100
void *mx_realloc(void *ptr, size_t size);                                       //100

/*  List Pack  */
t_list *mx_create_node(void *data);                                     //100
void mx_push_front(t_list **list, void *data);                          //100
void mx_push_back(t_list **list, void *data);                           //100
void mx_pop_front(t_list **head);                                       //60
void mx_pop_back(t_list **head);                                        //60
int mx_list_size(t_list *list);                                         //100
//t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *));

#endif //LIBMX_LIBMX_H
