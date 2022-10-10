/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 09:51:58 by mbarutel          #+#    #+#             */
/*   Updated: 2022/10/09 13:36:54 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static char get_char(void)
{
    int c;

    c = 0;
    read(STDIN_FILENO, &c, 1);
    return (c);
}

static void enable_raw(struct termios *term, struct termios *oterm)
{
    tcgetattr(STDIN_FILENO, oterm);
    ft_memcpy(term, oterm, sizeof(term));
    term->c_lflag &= ~(ICANON | ECHO);
    term->c_cc[VMIN] = 1;
    term->c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, term);
}

static void disable_raw(struct termios *oterm)
{
    tcsetattr(STDIN_FILENO, TCSANOW, oterm);
}

// static int get_next_ch(char c)
// {
//     char c;
    
//     c = get_char();
//     if (c == KEY_ESCAPE)
//     {
//         if ()
//     }
// }

int main(int ac, char **av)
{
    int             i;
    char            c;
    struct termios  term;
    struct termios  oterm;
    char            *line;
    int             l;
    
    if (ac <= 1)
        return (ERROR);
    i = 0;
    l = 0;
    while (get_next_line(STDIN_FILENO, &line))
    {
        l++;
        ft_printf("This happens\n");
        if (line)
            ft_strdel(&line);
    }
    while (++i < ac)
        ft_printf("%s\n", av[i]);
    ft_printf("%d", l);
    ft_printf("\033[%d;1H", l);
    while (1)
    {
        enable_raw(&term, &oterm);
        c = get_char();
        if (c == KEY_ESCAPE)
        {
            c = get_char();
            if (c == '[')
            {     
                c = get_char();
                if (c == 'A')
                    ft_printf("\r\033[%dA", 1);
                if (c == 'B')
                    ft_printf("\r\033[%dB", 1);
            }
        }
        disable_raw(&oterm);
        if (c == 'q')
            break ;
    }
    return (RESET);
}