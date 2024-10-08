#include <stdio.h>
/**
 * regex_match - checks whether a given pattern matches a given string
 * @str: the string given
 * @pattern: the regular expression given
 * Return: 1 otherwise 0
 */

int regex_match(char const *str, char const *pattern)
{
if (*str == '\0' && *pattern == '\0')
return (1);

if (*str != '\0' && *pattern == '\0')
{
return (0);
}
if (*(pattern + 1) == '*')
{
while ((*str == *pattern) || (*pattern == '.' && *str != '\0'))
{
if (regex_match(str, pattern + 2))
{
return (1);
}
str++;
}
return (regex_match(str, pattern + 2));
}
if (*str == *pattern || (*pattern == '.' && *str != '\0'))
{
return (regex_match(str + 1, pattern + 1));
}
return (0);
}
