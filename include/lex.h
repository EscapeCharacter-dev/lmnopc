#ifndef LMNOP_LEX_H
#define LMNOP_LEX_H

enum {
    LEX_LINT = 127,	// Integer literal
    LEX_LFLOAT,		// Float literal
    LEX_LSTR,		// String literal
    LEX_IDENT,		// Identifier
    LEX_PPLUS,		// ++
    LEX_MMINUS,		// --
    LEX_EQUALS,		// ==
    LEX_NEQUAL,		// !=
    LEX_GREQUAL,	// <=
    LEX_LEEQUAL,	// >=
    LEX_AMPERSANDS,	// &&
    LEX_PIPES,		// ||
    LEX_LARROWS,	// <<
    LEX_RARROWS,	// >>
    LEX_LARROWSEQU,	// <<=
    LEX_RARROWSEQU,	// >>=
    LEX_PLUSEQUAL,	// +=
    LEX_MINUSEQUAL,	// -=
    LEX_STAREQUAL,	// *=
    LEX_SLASHEQUAL,	// /=
    LEX_PEREQUAL,	// %=
    LEX_ANDEQUAL,	// &=
    LEX_PIPEEQUAL,	// |=
    LEX_CARETEQUAL,	// ^=
    LEX_ARROW,		// ->
    LEX_SIZEOF,		// sizeof
    LEX_LENGTHOF,	// lengthof
    LEX_BREAK,		// break
    LEX_CONTINUE,	// continue
    LEX_DEFAULT,	// default
    LEX_IF,			// if
    LEX_ELSE,		// else
    LEX_GOTO,		// goto
    LEX_WHILE,		// while
    LEX_DO,			// do
    LEX_FOR,		// for
    LEX_SWITCH,		// switch
    LEX_CASE,		// case
    LEX_RETURN,		// return
    LEX_REGISTER,	// register
    LEX_VOLATILE,	// volatile
    LEX_EXTERN,		// extern
    LEX_PUBLIC,		// public
    LEX_CLANG,		// clang
    LEX_I8,			// I8
    LEX_U8,			// U8
    LEX_I16,		// I16
    LEX_U16,		// U16
    LEX_I32,		// I32
    LEX_U32,		// U32
    LEX_I64,		// I64
    LEX_U64,		// U64
    LEX_F32,		// F32
    LEX_F64,		// F64
    LEX_VOID,		// void
    LEX_ENUM,		// enum
    LEX_UNION,		// union
    LEX_STRUCT,		// struct
    LEX_AUTOSTRUCT,	// autostruct
};

#endif
