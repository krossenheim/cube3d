/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/21 13:58:00 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/09/21 15:28:43 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

typedef struct s_key_role
{
    int				(* func)();
    int				key;
}  t_key_role;
# define N_KEYS_MAPPED 6
# define MAPPED_KEYS (t_key_role [N_KEYS_MAPPED]) {\
						(t_key_role){NULL, KEY_W},				\
						(t_key_role){NULL, KEY_S},				\
						(t_key_role){NULL, KEY_A},				\
						(t_key_role){NULL, KEY_D},				\
						(t_key_role){escape_pressed, KEY_ESC},		\
						(t_key_role){NULL, KEY_SPACE},			\
											}	
//Needed
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_SHIFT 65505
# define KEY_CTRL 65507
# define KEY_SPACE 32
# define KEY_TAB    65289

//Probably not needed
# define KEY_DEL 65535
# define KEY_ENTER  65293
# define KEY_ONE    49
# define KEY_TWO    50
# define KEY_THREE  51
# define KEY_FOUR   52

#endif