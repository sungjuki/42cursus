/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:13:36 by sungjuki          #+#    #+#             */
/*   Updated: 2022/04/02 16:00:32 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define TYPE "csdiupxX%"
# define FLAG "0-*+# "
# define NULL_STR "(null)"
/*
** printf("%[flags][width][.precision][length]formatspecifier", $(* pnt))
**	char	[flag]
** 		'-' 	: left align. 
**		'0'		: fill left width with '0'.
**		'+' 	: express sign.(bonus part) 
**		' ' 	: do not express options except minus sign if the case is.(bonus part)
**		'#'		: express base number ex) 0, 0x, 0X.(bonus part)
**	int		[width]
** 	int		[.precision]
**	int		[length]
**	char	[formatspecifier]
** 		%s print a string of characters.
** 		%p The void * pointer argument is printed in hexadecimal. 
**		%d print a decimal (base 10) number.
** 		%i print an integer in base 10.
** 		%u print an unsigned decimal (base 10) number.
** 		%x print a number in hexadecimal (base 16), with lowercase. 
**		%X print a number in hexadecimal (base 16), with uppercase.
**		%% print a percent sign.
*/

typedef struct s_options
{
	char	flag[7];
	int		width;
	int		precision;
	int		type;
}	t_options;

typedef struct s_box
{
	int			left_margin;
	int			right_margin;
	char		sign;
	int			zero_len;
	int			prefix_len;
	long long	value;
	int			value_len;
	char		base[20];
	int			base_len;
	int			precision;
}	t_box;
/*
**	int						left_margin; 	-> number of left_margin (=options -> width)
**	int						right_margin; 	-> number of right_margin (=options -> width)
**	char					sign; 			-> number sign
**	int						zero_len; 		-> number of zero char
**	int 					prefix_len; 	-> 0 -> not prefix, 2 -> 0x prefix_len = 2;
**	long long     			value; 			-> va_arg's argument 
**	int						value_len; 		-> length of str(va_arg)
**	char					base[20]; 		-> number_base
**	int						base_len; 		-> base_len
**	int						precision; 		-> precision
*/

/*
 ** ft_printf
 */
int				ft_printf(const char *format, ...);
int				ft_printf_sub(const char *format, va_list ap,
					t_options *options, t_box *box);

/*
 ** ft_printf_preprocess
 */
t_options		*ft_read_astrsk(t_options *options, va_list ap);
t_options		*ft_read_options(t_options *options,
					va_list ap, const char *format, int i);
int				ft_printf_boxing(t_options *options, t_box *box, va_list ap);

/*
 ** ft_printf_utils
 */
t_options		*init_options(t_options	*options);
t_box			*init_box(t_box *box);
int				options_flag_check(t_options *options);

/*
 ** ft_printf_utils2
 */
char			*ft_uitoa(unsigned int n);
void			itoa_rec(unsigned int n, int index, char **db_pnt);
char			*ull_to_hexbase(unsigned long long nbr, char *base_to);
int				get_malloc_size(unsigned long long dec, char *base_to);

/*
** ft_printf_boxing
*/
int				ft_boxing_value_len_n_precision(t_options *options, t_box *box);
int				ft_boxing_margin(t_options *options, t_box *box);
int				ft_boxing_precision(t_options *options, t_box *box);
int				ft_boxing_flag_n_base(t_options *options, t_box *box);

/*
** ft_printf_printphase
*/
int				ft_printf_type(t_options *options, t_box *box);

/*
** ft_printf_char
*/
int				ft_printf_leftmargin(t_box *box);
int				ft_printf_rightmargin(t_box *box);
int				ft_printf_char(t_box *box);

/*
** ft_printf_string
*/
int				ft_printf_leftmargin_str(t_box *box);
int				ft_printf_rightmargin_str(t_box *box);
int				ft_printf_str(t_box *box);

/*
** ft_printf_pnt
*/
int				ft_printf_pnt(t_box *box);

/*
** ft_printf_nbr
*/
int				ft_printf_nbr(t_box *box);
int				ft_print_sign_case_padding_nbr(t_box *box, char padding_char);
int				ft_print_no_sign_case_padding_nbr(t_box *box,
					char padding_char);
int				ft_printf_leftmargin_nbr(t_box *box);
int				ft_printf_rightmargin_nbr(t_box *box);

/*
** ft_printf_unsigned
*/
int				ft_printf_unsigned(t_box *box);

#endif
