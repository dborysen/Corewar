/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:58:50 by dborysen          #+#    #+#             */
/*   Updated: 2018/04/19 13:58:52 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

// int state_table[19][11] = 
// {
// 	{100, 105, 101, 106, 102, 108, 104, EOL, 112, 115, ERROR},
// 	{OPERATION, 101, 101, 110, ERROR, 103, OPERATION, OPERATION, OPERATION, ERROR, ERROR},
// 	{ERROR, ERROR, ERROR, 107, ERROR, 109, ERROR, ERROR, ERROR, 117, ERROR},
// 	{T_LAB, T_LAB, T_LAB, T_LAB, T_LAB, T_LAB, T_LAB, T_LAB, T_LAB, T_LAB, T_LAB},
// 	{SEP_CHAR, SEP_CHAR, SEP_CHAR, SEP_CHAR, SEP_CHAR, SEP_CHAR, SEP_CHAR, SEP_CHAR, SEP_CHAR, SEP_CHAR, SEP_CHAR},
// 	{OPERATION, 101, 101, 111, ERROR, 103, ERROR, ERROR, OPERATION, ERROR, ERROR},
// 	{T_IND, 106, 110, 106, ERROR, ERROR, T_IND, T_IND, T_IND, ERROR, ERROR},
// 	{T_DIR, ERROR, ERROR, 107, ERROR, ERROR, T_DIR, T_DIR, T_DIR, ERROR, ERROR},
// 	{ERROR, 114, 114, 114, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR},
// 	{ERROR, 113, 113, 113, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR},
// 	{ERROR, 110, 110, 110, ERROR, 103, ERROR, T_LAB, T_LAB, ERROR, ERROR},
// 	{T_REG, 110, 110, 111, ERROR, 103, T_REG, T_REG, T_REG, ERROR, ERROR},
// 	{112, 112, 112, 112, 112, 112, 112, COMMENT, 112, 112, 112},
// 	{T_DIR, 113, 113, 113, ERROR, ERROR, T_DIR, T_DIR, T_DIR, ERROR, ERROR},
// 	{T_IND, 114, 114, 114, ERROR, ERROR, T_IND, T_IND, T_IND, ERROR, ERROR},
// 	{ERROR, ERROR, ERROR, 116, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR},
// 	{T_IND, ERROR, ERROR, 116, ERROR, ERROR, T_IND, T_IND, T_IND, ERROR, ERROR},
// 	{ERROR, ERROR, ERROR, 118, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR},
// 	{T_DIR, ERROR, ERROR, 118, ERROR, ERROR, T_DIR, T_DIR, T_DIR, ERROR, ERROR},
// };