/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "parser.y"

	#include "symtable.h"
	#include <cmath>
	int yylex();
	void yyerror(const char *s);
	void gencode(char op, int arg1, int arg2,string tname);
	int add_temptotable(ValueType vtype);
	void emit(string command, int arg1, int arg2, int output, int arg_count);
	int convert_to_propertype(int arg1,int arg2);
	int convert_to_assignment(int lside, int assignment);
	int addlabel();
	string determine_type(int arg1);
	int add_referencetotable(ValueType vtype, int cont,int offs);
	int tempno = 0;
	int context = 1;
	int localcontext = 1;
	int negoffset = 0;
	bool addressReference = false;
	int functionaloffset = 8; // 12 dla funkcji
	string determine_offset(int ind,string command );
	void printAndClearFunctionBody();
	vector<int> help;
	vector<int> help_exp;	
	vector<int> args;
	vector<string> function_body;

#line 98 "parsertab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parsertab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BEGIN_T = 3,                    /* BEGIN_T  */
  YYSYMBOL_END_T = 4,                      /* END_T  */
  YYSYMBOL_NUMBER = 5,                     /* NUMBER  */
  YYSYMBOL_INTEGER = 6,                    /* INTEGER  */
  YYSYMBOL_REAL = 7,                       /* REAL  */
  YYSYMBOL_ID = 8,                         /* ID  */
  YYSYMBOL_PROGRAM = 9,                    /* PROGRAM  */
  YYSYMBOL_VAR = 10,                       /* VAR  */
  YYSYMBOL_ASSIGNOP = 11,                  /* ASSIGNOP  */
  YYSYMBOL_ADDOP = 12,                     /* ADDOP  */
  YYSYMBOL_MULOP = 13,                     /* MULOP  */
  YYSYMBOL_RELOP = 14,                     /* RELOP  */
  YYSYMBOL_INPUT_OUTPUT = 15,              /* INPUT_OUTPUT  */
  YYSYMBOL_READOP = 16,                    /* READOP  */
  YYSYMBOL_WRITEOP = 17,                   /* WRITEOP  */
  YYSYMBOL_ARRAY = 18,                     /* ARRAY  */
  YYSYMBOL_OF = 19,                        /* OF  */
  YYSYMBOL_IF = 20,                        /* IF  */
  YYSYMBOL_WHILE = 21,                     /* WHILE  */
  YYSYMBOL_DO = 22,                        /* DO  */
  YYSYMBOL_ELSE = 23,                      /* ELSE  */
  YYSYMBOL_THEN = 24,                      /* THEN  */
  YYSYMBOL_OR = 25,                        /* OR  */
  YYSYMBOL_NOT = 26,                       /* NOT  */
  YYSYMBOL_FUNCTION = 27,                  /* FUNCTION  */
  YYSYMBOL_PROCEDURE = 28,                 /* PROCEDURE  */
  YYSYMBOL_EQ = 29,                        /* EQ  */
  YYSYMBOL_NEQ = 30,                       /* NEQ  */
  YYSYMBOL_LT = 31,                        /* LT  */
  YYSYMBOL_LEQ = 32,                       /* LEQ  */
  YYSYMBOL_GEQ = 33,                       /* GEQ  */
  YYSYMBOL_GT = 34,                        /* GT  */
  YYSYMBOL_35_ = 35,                       /* '('  */
  YYSYMBOL_36_ = 36,                       /* ','  */
  YYSYMBOL_37_ = 37,                       /* ')'  */
  YYSYMBOL_38_ = 38,                       /* ';'  */
  YYSYMBOL_39_ = 39,                       /* '.'  */
  YYSYMBOL_40_ = 40,                       /* ':'  */
  YYSYMBOL_41_ = 41,                       /* '['  */
  YYSYMBOL_42_ = 42,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_start = 44,                     /* start  */
  YYSYMBOL_program = 45,                   /* program  */
  YYSYMBOL_46_1 = 46,                      /* $@1  */
  YYSYMBOL_47_2 = 47,                      /* $@2  */
  YYSYMBOL_48_3 = 48,                      /* $@3  */
  YYSYMBOL_declarations = 49,              /* declarations  */
  YYSYMBOL_declaration_list = 50,          /* declaration_list  */
  YYSYMBOL_declaration = 51,               /* declaration  */
  YYSYMBOL_type = 52,                      /* type  */
  YYSYMBOL_standard_type = 53,             /* standard_type  */
  YYSYMBOL_identifier_list = 54,           /* identifier_list  */
  YYSYMBOL_subprogram_declarations = 55,   /* subprogram_declarations  */
  YYSYMBOL_subprogram_declaration = 56,    /* subprogram_declaration  */
  YYSYMBOL_subprogram_head = 57,           /* subprogram_head  */
  YYSYMBOL_58_4 = 58,                      /* $@4  */
  YYSYMBOL_59_5 = 59,                      /* @5  */
  YYSYMBOL_arguments = 60,                 /* arguments  */
  YYSYMBOL_parameter_list = 61,            /* parameter_list  */
  YYSYMBOL_compound_statement = 62,        /* compound_statement  */
  YYSYMBOL_optional_statements = 63,       /* optional_statements  */
  YYSYMBOL_statement_list = 64,            /* statement_list  */
  YYSYMBOL_statement = 65,                 /* statement  */
  YYSYMBOL_66_6 = 66,                      /* @6  */
  YYSYMBOL_67_7 = 67,                      /* $@7  */
  YYSYMBOL_68_8 = 68,                      /* @8  */
  YYSYMBOL_69_9 = 69,                      /* $@9  */
  YYSYMBOL_assignment_statement = 70,      /* assignment_statement  */
  YYSYMBOL_variable = 71,                  /* variable  */
  YYSYMBOL_procedure_statement = 72,       /* procedure_statement  */
  YYSYMBOL_expression_list = 73,           /* expression_list  */
  YYSYMBOL_expression = 74,                /* expression  */
  YYSYMBOL_simple_expression = 75,         /* simple_expression  */
  YYSYMBOL_term = 76,                      /* term  */
  YYSYMBOL_factor = 77                     /* factor  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   129

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      35,    37,     2,     2,    36,     2,    39,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    38,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    62,    62,    65,    66,    66,    65,    71,    72,    76,
      77,    81,   149,   150,   162,   163,   166,   171,   178,   179,
     182,   191,   190,   224,   223,   247,   248,   251,   281,   314,
     317,   318,   321,   322,   326,   327,   328,   330,   337,   329,
     349,   357,   348,   369,   380,   392,   424,   432,   440,   443,
     457,   458,   461,   462,   503,   504,   505,   529,   555,   556,
     583,   584,   645,   649,   653
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "BEGIN_T", "END_T",
  "NUMBER", "INTEGER", "REAL", "ID", "PROGRAM", "VAR", "ASSIGNOP", "ADDOP",
  "MULOP", "RELOP", "INPUT_OUTPUT", "READOP", "WRITEOP", "ARRAY", "OF",
  "IF", "WHILE", "DO", "ELSE", "THEN", "OR", "NOT", "FUNCTION",
  "PROCEDURE", "EQ", "NEQ", "LT", "LEQ", "GEQ", "GT", "'('", "','", "')'",
  "';'", "'.'", "':'", "'['", "']'", "$accept", "start", "program", "$@1",
  "$@2", "$@3", "declarations", "declaration_list", "declaration", "type",
  "standard_type", "identifier_list", "subprogram_declarations",
  "subprogram_declaration", "subprogram_head", "$@4", "@5", "arguments",
  "parameter_list", "compound_statement", "optional_statements",
  "statement_list", "statement", "@6", "$@7", "@8", "$@9",
  "assignment_statement", "variable", "procedure_statement",
  "expression_list", "expression", "simple_expression", "term", "factor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-94)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-45)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      12,    15,    53,   -94,    20,   -94,    63,    52,    70,    48,
      51,   -94,    81,    84,   -94,   -94,     8,   -94,    -5,   -94,
      84,   -94,    85,    41,    35,   -94,   -94,   -94,   -94,    54,
      56,   -94,    88,    90,    96,    62,    81,    97,   -94,   -94,
     -94,    49,    64,   -94,    96,    65,    66,    66,     2,    71,
      72,    -1,   -94,   -94,   101,    73,   -94,   -94,    98,   -94,
     -94,   -94,    74,    84,    68,    76,    -1,    -1,    -1,    -1,
     -94,    -9,     1,     1,    -1,   -94,   -94,    42,    99,   -94,
      -1,   -94,    49,    -1,   105,    24,    36,    69,   -94,    43,
     -94,    75,    45,    47,    -1,    99,   -94,    78,    92,     1,
      -1,     1,     1,   100,   -94,   -94,    77,    41,   -94,    84,
      80,    -1,   -94,   -94,   -94,   -94,    50,   -94,    49,    99,
       4,    99,   -94,   -94,   102,   -94,    32,   -94,   -94,   -94,
     -94,    49,    69,    41,   103,   -94,   -94,   -94,    49,   -94
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     0,     0,     0,
       0,     3,     8,     0,     4,    16,     8,     9,     0,    19,
       0,     7,     0,     0,     5,    10,    17,    14,    15,     0,
       0,    12,     0,     0,     0,     0,     8,     0,    11,    21,
      23,    31,     0,    18,     0,     0,    26,    26,    48,     0,
       0,     0,    40,    36,     0,    30,    32,    34,     0,    35,
       6,    20,     0,     0,     0,     0,     0,     0,     0,     0,
      62,    44,     0,     0,     0,    60,    37,    52,    54,    58,
       0,    29,     0,     0,     0,     0,     0,     0,    24,     0,
      50,     0,     0,     0,     0,    55,    64,     0,     0,     0,
       0,     0,     0,     0,    33,    43,     0,     0,    25,     0,
       0,     0,    49,    45,    46,    47,     0,    63,     0,    56,
      53,    57,    59,    41,     0,    27,     0,    22,    51,    61,
      38,     0,     0,     0,     0,    42,    13,    28,     0,    39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -94,   -94,   -94,   -94,   -94,   -94,    -8,   -94,   104,   -93,
     -82,   -60,   -94,   -94,   -94,   -94,   -94,    82,   -94,   -22,
     -94,   -94,   -80,   -94,   -94,   -94,   -94,   -94,   -41,   -94,
     -49,   -50,    23,   -57,   -63
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    12,    19,    34,    14,    16,    17,    30,
      31,    18,    24,    35,    36,    46,    47,    64,    86,    53,
      54,    55,    56,    98,   134,    80,   131,    57,    75,    59,
      89,    90,    77,    78,    79
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,    76,   104,    85,    70,   110,    70,    71,    21,    71,
      96,    72,    42,   -44,   125,    95,    99,    91,    13,    92,
      93,     1,    61,     4,    97,    73,    94,    73,    44,   101,
     103,    22,    67,   105,    74,    23,    74,    66,   130,   122,
     137,    58,   119,    67,   121,   116,    20,    27,    28,   126,
     136,   135,    41,     5,    99,     6,   100,    48,   139,    29,
      22,   128,    32,    33,   107,    49,    50,   101,    22,    51,
      52,     7,   133,   108,   109,    27,    28,    58,     9,   111,
     112,   111,   114,   111,   115,    10,   111,   129,     8,    11,
      58,    13,    15,    26,    38,    37,    39,    58,    40,    41,
      43,    63,    45,    60,    62,    81,    68,    69,    87,    83,
     106,    82,   102,    84,    88,   117,   118,   113,   127,   124,
       0,   132,   123,   120,    25,     0,   138,     0,     0,    65
};

static const yytype_int16 yycheck[] =
{
      41,    51,    82,    63,     5,    87,     5,     8,    16,     8,
      73,    12,    34,    11,   107,    72,    12,    67,    10,    68,
      69,     9,    44,     8,    74,    26,    35,    26,    36,    25,
      80,    36,    41,    83,    35,    40,    35,    35,   118,   102,
     133,    82,    99,    41,   101,    94,    38,     6,     7,   109,
     132,   131,     3,     0,    12,    35,    14,     8,   138,    18,
      36,   111,    27,    28,    40,    16,    17,    25,    36,    20,
      21,     8,    40,    37,    38,     6,     7,   118,     8,    36,
      37,    36,    37,    36,    37,    37,    36,    37,    36,    38,
     131,    10,     8,     8,    38,    41,     8,   138,     8,     3,
      38,    35,     5,    39,    39,     4,    35,    35,    40,    11,
       5,    38,    13,    39,    38,    37,    24,    42,    38,    42,
      -1,    19,    22,   100,    20,    -1,    23,    -1,    -1,    47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    44,    45,     8,     0,    35,     8,    36,     8,
      37,    38,    46,    10,    49,     8,    50,    51,    54,    47,
      38,    49,    36,    40,    55,    51,     8,     6,     7,    18,
      52,    53,    27,    28,    48,    56,    57,    41,    38,     8,
       8,     3,    62,    38,    49,     5,    58,    59,     8,    16,
      17,    20,    21,    62,    63,    64,    65,    70,    71,    72,
      39,    62,    39,    35,    60,    60,    35,    41,    35,    35,
       5,     8,    12,    26,    35,    71,    74,    75,    76,    77,
      68,     4,    38,    11,    39,    54,    61,    40,    38,    73,
      74,    74,    73,    73,    35,    76,    77,    74,    66,    12,
      14,    25,    13,    74,    65,    74,     5,    40,    37,    38,
      53,    36,    37,    42,    37,    37,    73,    37,    24,    76,
      75,    76,    77,    22,    42,    52,    54,    38,    74,    37,
      65,    69,    19,    40,    67,    65,    53,    52,    23,    65
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    46,    47,    48,    45,    49,    49,    50,
      50,    51,    52,    52,    53,    53,    54,    54,    55,    55,
      56,    58,    57,    59,    57,    60,    60,    61,    61,    62,
      63,    63,    64,    64,    65,    65,    65,    66,    67,    65,
      68,    69,    65,    70,    71,    71,    72,    72,    72,    72,
      73,    73,    74,    74,    75,    75,    75,    75,    76,    76,
      77,    77,    77,    77,    77
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     0,     0,    15,     3,     0,     1,
       3,     4,     1,     9,     1,     1,     1,     3,     3,     0,
       3,     0,     7,     0,     5,     3,     0,     3,     5,     3,
       1,     0,     1,     3,     1,     1,     1,     0,     0,     8,
       0,     0,     6,     3,     1,     4,     4,     4,     1,     4,
       1,     3,     1,     3,     1,     2,     3,     3,     1,     3,
       1,     4,     1,     3,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* $@1: %empty  */
#line 65 "parser.y"
                                     {incrementoffset(12);}
#line 1249 "parsertab.cpp"
    break;

  case 4: /* $@2: %empty  */
#line 66 "parser.y"
                 {emit_begend(1);}
#line 1255 "parsertab.cpp"
    break;

  case 5: /* $@3: %empty  */
#line 66 "parser.y"
                                                          {cout << "lab0:" << endl;}
#line 1261 "parsertab.cpp"
    break;

  case 6: /* program: PROGRAM ID '(' ID ',' ID ')' ';' $@1 declarations $@2 subprogram_declarations $@3 compound_statement '.'  */
#line 67 "parser.y"
                           {emit_begend(2);}
#line 1267 "parsertab.cpp"
    break;

  case 11: /* declaration: identifier_list ':' type ';'  */
#line 81 "parser.y"
                                 {
									if(context ==1)
									{
										vector<int>::iterator ids;
										ValueType v;
										if(yyvsp[-1] <= REA || yyvsp[-1]<= INT)
										{
											if(yyvsp[-1] == INT)
											{
												v = INT;
											}
											else 
												v = REA;
											for(ids = help.begin(); ids != help.end(); ids++)
											{
												modifyidentifier(*ids, v);
											}
										}
										else
										{
											yyvsp[-1] = yyvsp[-1]-REA-INT;
											v = symtable[yyvsp[-1]].vtype;
											for(ids = help.begin(); ids != help.end(); ids++)
											{
												modifyarray(*ids, v,symtable[yyvsp[-1]].arr.size,yyvsp[-1]);
											}
										}
										help.clear();
									}
									else
									{
										vector<int>::iterator ids;
										ValueType v;
										if(yyvsp[-1] <= REA || yyvsp[-1]<= INT)
										{
											if(yyvsp[-1] == INT)
											{
												v = INT;
											}
											else 
												v = REA;
											for(ids = help.begin(); ids != help.end(); ids++)
											{
												if(v == REA)
													negoffset -= 8;
												else 
													negoffset -= 4;
												modifyidentifier(*ids, v,negoffset,localcontext);
											}
										}
										else
										{
											yyvsp[-1] = yyvsp[-1]-REA-INT;
											v = symtable[yyvsp[-1]].vtype;
											for(ids = help.begin(); ids != help.end(); ids++)
											{
												if(v == REA)
													negoffset -= 8*symtable[yyvsp[-1]].arr.size;
												else 
													negoffset -= 4*symtable[yyvsp[-1]].arr.size;
												modifyarray(*ids, v,symtable[yyvsp[-1]].arr.size,yyvsp[-1],negoffset,localcontext);
											}
										}
										help.clear();									
									}
								 }
#line 1338 "parsertab.cpp"
    break;

  case 12: /* type: standard_type  */
#line 149 "parser.y"
                      {yyval = yyvsp[0];}
#line 1344 "parsertab.cpp"
    break;

  case 13: /* type: ARRAY '[' NUMBER '.' '.' NUMBER ']' OF standard_type  */
#line 150 "parser.y"
                                                             {
															ValueType v;
															if(yyvsp[0] == REA)
																v = REA;
															else
																v = INT;
															int v1 = stoi(symtable[yyvsp[-6]].name);
															int v2 = stoi(symtable[yyvsp[-3]].name);
															yyval = addnonetotable(v1, v2, v)+INT+REA;
														 }
#line 1359 "parsertab.cpp"
    break;

  case 14: /* standard_type: INTEGER  */
#line 162 "parser.y"
                {yyval = yyvsp[0];}
#line 1365 "parsertab.cpp"
    break;

  case 15: /* standard_type: REAL  */
#line 163 "parser.y"
                {yyval = yyvsp[0];}
#line 1371 "parsertab.cpp"
    break;

  case 16: /* identifier_list: ID  */
#line 166 "parser.y"
                                                        {
									help.push_back(yyvsp[0]);
									if(context > 1)
										args.push_back(yyvsp[0]);
								}
#line 1381 "parsertab.cpp"
    break;

  case 17: /* identifier_list: identifier_list ',' ID  */
#line 171 "parser.y"
                                {
									help.push_back(yyvsp[0]);
									if(context > 1)
										args.push_back(yyvsp[0]);
								}
#line 1391 "parsertab.cpp"
    break;

  case 20: /* subprogram_declaration: subprogram_head declarations compound_statement  */
#line 182 "parser.y"
                                                          {
														context--; 
														negoffset=0;
														printAndClearFunctionBody();
														args.clear();
													  }
#line 1402 "parsertab.cpp"
    break;

  case 21: /* $@4: %empty  */
#line 191 "parser.y"
                                {
					emit(symtable[yyvsp[0]].name+string(":"),-1,-1,-1,0);
					localcontext++;
					context++;
					yyvsp[-1] = addfunctotable(yyvsp[0],localcontext,8);
					functionaloffset = 12;
					
				}
#line 1415 "parsertab.cpp"
    break;

  case 22: /* subprogram_head: FUNCTION ID $@4 arguments ':' standard_type ';'  */
#line 200 "parser.y"
                                {
					if(yyvsp[-1] == REA)
					{
						symtable[yyvsp[-5]].vtype = REA;
					}
					else if (yyvsp[-1] == INT)
						symtable[yyvsp[-5]].vtype = INT;
					//cout << ValueTypeToString(symtable[$2].vtype) << symtable[$1].vtype<<endl;
					if(yyvsp[-3] != -1)
					{
						vector<int>::iterator ids;
						for(ids = args.end()-1; ids >= args.begin(); ids--)
							{
								//cout << symtable[*ids].name<<endl;
								symtable[yyvsp[-6]].function_args.push_back(*ids);
								modifyreference(*ids,functionaloffset);
								functionaloffset +=4;
							}
						help.clear();
					}
					yyval = yyvsp[-6];
				}
#line 1442 "parsertab.cpp"
    break;

  case 23: /* @5: %empty  */
#line 224 "parser.y"
                                {
					emit(symtable[yyvsp[0]].name+string(":"),-1,-1,-1,0);
					localcontext++;
					context++;
					yyvsp[-1] = addfunctotable(yyvsp[0],localcontext,-1);
					functionaloffset = 8;
				}
#line 1454 "parsertab.cpp"
    break;

  case 24: /* subprogram_head: PROCEDURE ID @5 arguments ';'  */
#line 232 "parser.y"
                                {
					if(yyvsp[-2] != -1)
					{
						vector<int> ar;
						vector<int>::iterator ids;
						for(ids = help.begin(); ids != help.end(); ids++)
						{
							ar.push_back(*ids);
						}
						symtable[yyvsp[-4]].function_args =ar;
						help.clear();
					}
				}
#line 1472 "parsertab.cpp"
    break;

  case 25: /* arguments: '(' parameter_list ')'  */
#line 247 "parser.y"
                                {yyval = 1;}
#line 1478 "parsertab.cpp"
    break;

  case 26: /* arguments: %empty  */
#line 248 "parser.y"
                        {yyval = -1;}
#line 1484 "parsertab.cpp"
    break;

  case 27: /* parameter_list: identifier_list ':' type  */
#line 252 "parser.y"
                                                                          {
										vector<int>::iterator ids;
										ValueType v;
										if(yyvsp[0] <= REA || yyvsp[0]<= INT)
										{
											if(yyvsp[0] == INT)
											{
												v = INT;
											}
											else 
												v = REA;
											for(ids = help.end() - 1; ids >= help.begin();ids--)
											{
												modifyreference(*ids, v,functionaloffset,localcontext,-1);
											}
											help.clear();
										}
										else
										{
											
											yyvsp[0] = yyvsp[0]-REA-INT;
											v = symtable[yyvsp[0]].vtype;
											for(ids = help.end() - 1; ids >= help.begin();ids--)
											{
												modifyreference(*ids, v,functionaloffset,localcontext,yyvsp[0]);
											}
											help.clear();
										}
									}
#line 1518 "parsertab.cpp"
    break;

  case 28: /* parameter_list: parameter_list ';' identifier_list ':' type  */
#line 282 "parser.y"
                                                                          {
										vector<int>::iterator ids;
										ValueType v;
										if(yyvsp[0] <= REA || yyvsp[0]<= INT)
										{
											if(yyvsp[0] == INT)
											{
												v = INT;
											}
											else 
												v = REA;
											
											for(ids = help.end() - 1; ids >= help.begin();ids--)
											{
												modifyreference(*ids, v,functionaloffset,localcontext,-1 );
											}
											help.clear();
										}
										else
										{
											
											yyvsp[0] = yyvsp[0]-REA-INT;
											v = symtable[yyvsp[0]].vtype;
											for(ids = help.end() - 1; ids >= help.begin();ids--)
											{
												modifyreference(*ids, v,functionaloffset,localcontext,yyvsp[0]);
											}
										}
											help.clear();
									}
#line 1553 "parsertab.cpp"
    break;

  case 37: /* @6: %empty  */
#line 330 "parser.y"
                {
			int then = addlabel();
			int false_number = addtotable("0", symtable[yyvsp[0]].vtype);
			emit(string("je.i"),yyvsp[0],false_number,then,3);
			yyval = then;
		}
#line 1564 "parsertab.cpp"
    break;

  case 38: /* $@7: %empty  */
#line 337 "parser.y"
                {
			int elsel = addlabel();
			emit(string("jump.i"), -1,-1,elsel,1);
			emit(symtable[yyvsp[-2]].name+string(":"),-1,-1,-1,0);
			yyvsp[-1] = elsel;
		}
#line 1575 "parsertab.cpp"
    break;

  case 39: /* statement: IF expression @6 THEN statement $@7 ELSE statement  */
#line 344 "parser.y"
                {
			emit(symtable[yyvsp[-4]].name+string(":"),-1,-1,-1,0);
			
		}
#line 1584 "parsertab.cpp"
    break;

  case 40: /* @8: %empty  */
#line 349 "parser.y"
                {
            int loop = addlabel();
            int secondloop = addlabel();
            emit(symtable[secondloop].name+string(":"),-1,-1,-1,0);
            yyval = loop;
            yyvsp[0] = secondloop;
		}
#line 1596 "parsertab.cpp"
    break;

  case 41: /* $@9: %empty  */
#line 357 "parser.y"
                {
			int false_number = addtotable("0", symtable[yyvsp[-2]].vtype);
			emit(string("je.i"),yyvsp[-1],false_number,yyvsp[-2],3);
		}
#line 1605 "parsertab.cpp"
    break;

  case 42: /* statement: WHILE @8 expression DO $@9 statement  */
#line 362 "parser.y"
                {
			emit(string("jump.i"), -1,-1,yyvsp[-5],1);
			emit(symtable[yyvsp[-4]].name+string(":"),-1,-1,-1,0);
		}
#line 1614 "parsertab.cpp"
    break;

  case 43: /* assignment_statement: variable ASSIGNOP expression  */
#line 369 "parser.y"
                                        {
								int position = convert_to_assignment(yyvsp[-2],yyvsp[0]);
								if(position == -1)
								{
									gencode(yyvsp[-1],yyvsp[0],yyvsp[-2],symtable[yyvsp[-2]].name);
								}
								else
									gencode(yyvsp[-1],position,yyvsp[-2],symtable[yyvsp[-2]].name);
							}
#line 1628 "parsertab.cpp"
    break;

  case 44: /* variable: ID  */
#line 380 "parser.y"
                        {   
				if(symtable[yyvsp[0]].type == FUNC && ((symtable[yyvsp[0]].context != localcontext)||context == 1))
				{
					int t = add_temptotable(symtable[yyvsp[0]].vtype);
					emit(string("push.i"),-1,-1,t,1);
					emit(string("call.i"),-1,-1,yyvsp[0],1);
					emit(string("incsp.i"),-1,-1,addtotable(to_string(4), INT),1);
					yyval = t;
				}
				else
					yyval = yyvsp[0];
			}
#line 1645 "parsertab.cpp"
    break;

  case 45: /* variable: ID '[' expression ']'  */
#line 393 "parser.y"
                                                        {
								if(symtable[yyvsp[-1]].vtype == REA) {
								int t = add_temptotable(INT);
								emit(string("realtoint.r"), yyvsp[-1], -1, t, 2);
								yyvsp[-1] = t;
								}
								int val = addtotable(to_string(symtable[yyvsp[-3]].arr.start), symtable[yyvsp[-3]].vtype);
								int t2 = add_temptotable(INT);
								emit(string("sub.i"),yyvsp[-1],val,t2,3);
								if(symtable[yyvsp[-3]].vtype == REA)
									val = addtotable(to_string(8), REA);
								else
									val = addtotable(to_string(4),INT);
								emit(string("mul.i"),t2,val,t2,3);
								int ref = -1;
								if(context == 1)
								{
									ref = add_referencetotable(symtable[yyvsp[-3]].vtype,context,4);
								}
								else
								{
									negoffset -=4;
									ref = add_referencetotable(symtable[yyvsp[-3]].vtype,localcontext,negoffset);									
								}
								val = addtotable(to_string(symtable[yyvsp[-3]].offset),INT);
								addressReference = true;
								emit(string("add.i"),yyvsp[-3],t2,ref,3);
								yyval = ref;
							}
#line 1679 "parsertab.cpp"
    break;

  case 46: /* procedure_statement: READOP '(' expression_list ')'  */
#line 424 "parser.y"
                                        {
								vector<int>::iterator ids;
								for(ids = help_exp.begin(); ids != help_exp.end();ids++)
								{
									emit(string("read")+determine_type(*ids),-1,-1,*ids,1);
								}
								help_exp.clear();
							}
#line 1692 "parsertab.cpp"
    break;

  case 47: /* procedure_statement: WRITEOP '(' expression_list ')'  */
#line 432 "parser.y"
                                        {
										vector<int>::iterator ids;
										for(ids = help_exp.begin(); ids != help_exp.end();ids++)
										{
											emit(string("write")+determine_type(*ids),-1,-1,*ids,1);
										}
										help_exp.clear();
									}
#line 1705 "parsertab.cpp"
    break;

  case 48: /* procedure_statement: ID  */
#line 440 "parser.y"
                {
					emit("call.i",-1,-1,yyvsp[0],1);				
			}
#line 1713 "parsertab.cpp"
    break;

  case 49: /* procedure_statement: ID '(' expression_list ')'  */
#line 444 "parser.y"
                        {
				int incsp = 0;
				vector<int>::iterator ids;
				for(ids = help_exp.begin(); ids != help_exp.end(); ids++, incsp += 4) {
					emit("push.i",-1,-1,*ids,1);
				}
				help_exp.clear();
				emit("call.i",-1,-1,yyvsp[-3],1);
				int num = addtotable(to_string(incsp), INT);
				emit("incsp.i",-1,-1,num,1);
			}
#line 1729 "parsertab.cpp"
    break;

  case 50: /* expression_list: expression  */
#line 457 "parser.y"
                        {help_exp.push_back(yyvsp[0]);}
#line 1735 "parsertab.cpp"
    break;

  case 51: /* expression_list: expression_list ',' expression  */
#line 458 "parser.y"
                                        {help_exp.push_back(yyvsp[0]);}
#line 1741 "parsertab.cpp"
    break;

  case 53: /* expression: simple_expression RELOP simple_expression  */
#line 462 "parser.y"
                                               {
													int position = add_temptotable(INT);
													int jump_label = addlabel();
													string command = string("");
													switch(yyvsp[-1])
													{
														case EQ:
															command = string("je")+ determine_type(yyvsp[-2]);
															break;
														case NEQ:
															command = string("jne")+ determine_type(yyvsp[-2]);
															break;
														case LT:
															command = string("jl")+ determine_type(yyvsp[-2]);
															break;
														case LEQ:
															command = string("jle")+ determine_type(yyvsp[-2]);
															break;
														case GT:
															command = string("jg")+ determine_type(yyvsp[-2]);
															break;
														case GEQ:
															command = string("jge")+ determine_type(yyvsp[-2]);
															break;
													}
													emit(command, yyvsp[-2], yyvsp[0], jump_label,3);
													int false_number = addtotable("0", INT);
													int end_jump = addlabel();
													gencode('=',false_number,-1,symtable[position].name);
													

													emit(string("jump.i"), -1,-1,end_jump,1);
													emit(symtable[jump_label].name+string(":"),-1,-1,-1,0);
													int true_number = addtotable("1", INT);
													gencode('=',true_number,-1,symtable[position].name);
													
													emit(symtable[end_jump].name+string(":"),-1,-1,-1,0);
													yyval = position;
												}
#line 1785 "parsertab.cpp"
    break;

  case 56: /* simple_expression: simple_expression ADDOP term  */
#line 505 "parser.y"
                                       {
										int  position = 0;
										int new_position = -1;
										position = convert_to_propertype(yyvsp[-2],yyvsp[0]);
										if(position == -1)
										{
											position = add_temptotable(symtable[yyvsp[-2]].vtype);
										}
										else
											new_position = add_temptotable(REA);
										if(new_position == -1)
										{
											yyval = position;
											gencode(yyvsp[-1],yyvsp[-2],yyvsp[0],symtable[position].name);
										}
										else
										{
											if(symtable[yyvsp[-2]].vtype == INT)
												gencode(yyvsp[-1],position,yyvsp[0],symtable[new_position].name);
											else
												gencode(yyvsp[-1],yyvsp[-2],position,symtable[new_position].name);
											yyval = new_position;
										}
								}
#line 1814 "parsertab.cpp"
    break;

  case 57: /* simple_expression: simple_expression OR term  */
#line 529 "parser.y"
                                    {
									int  position = 0;
									int new_position = -1;
									position = convert_to_propertype(yyvsp[-2],yyvsp[0]);
									if(position == -1)
									{
										position = add_temptotable(symtable[yyvsp[-2]].vtype);
									}
									else
										new_position = add_temptotable(REA);
									if(new_position == -1)
									{
										yyval = position;
										gencode(yyvsp[-1],yyvsp[-2],yyvsp[0],symtable[position].name);
									}
									else
									{
										if(symtable[yyvsp[-2]].vtype == INT)
											gencode(yyvsp[-1],position,yyvsp[0],symtable[new_position].name);
										else
											gencode(yyvsp[-1],yyvsp[-2],position,symtable[new_position].name);
										yyval = new_position;
									}
								}
#line 1843 "parsertab.cpp"
    break;

  case 59: /* term: term MULOP factor  */
#line 556 "parser.y"
                        {
										int  position = 0;
										int new_position = -1;
										position = convert_to_propertype(yyvsp[-2],yyvsp[0]);
										if(position == -1)
										{
											position = add_temptotable(symtable[yyvsp[-2]].vtype);
										}
										else
											new_position = add_temptotable(REA);
										if(new_position == -1)
										{
											yyval = position;
											gencode(yyvsp[-1],yyvsp[-2],yyvsp[0],symtable[position].name);
										}
										else
										{
											if(symtable[yyvsp[-2]].vtype == INT)
												gencode(yyvsp[-1],position,yyvsp[0],symtable[new_position].name);
											else
												gencode(yyvsp[-1],yyvsp[-2],position,symtable[new_position].name);
											yyval = new_position;
										}
						}
#line 1872 "parsertab.cpp"
    break;

  case 61: /* factor: ID '(' expression_list ')'  */
#line 585 "parser.y"
                        {
				if(symtable[yyvsp[-3]].type == FUNC)
				{
					int incsp = 0;
					vector<int>::iterator ids;
					vector<int>::iterator ass;
					for(ass = help_exp.begin(); ass != help_exp.end(); ass++)
					{
						//cout << symtable[*ass].name <<"przed"<<endl;
					}
					int num_args = symtable[yyvsp[-3]].function_args.size();
					ass = help_exp.end() - num_args;
					for(ids = symtable[yyvsp[-3]].function_args.end() - 1; 
						ids >= symtable[yyvsp[-3]].function_args.begin(); 
						ids--, ass++, incsp += 4) 
					{
						int position = *ass;

						if(symtable[*ass].type == NUM)
						{
							position = add_temptotable(symtable[*ids].vtype);
							if(symtable[*ass].vtype == REA && symtable[*ids].vtype == INT)
								symtable[*ass].name = to_string(stoi(symtable[*ass].name));
							emit(string("mov" + determine_type(*ids)), *ass, -1, position, 2);
						}
						if(symtable[*ass].type == IDENTIFIER)
						{
							int new_position = -1;
							if(symtable[*ass].vtype != symtable[*ids].vtype)
							{
								new_position = add_temptotable(symtable[*ids].vtype);
								if(symtable[*ass].vtype == INT)
								{   
									emit("inttoreal.i", *ass, -1, new_position, 2);
								}
								else
								{
									emit("realtoint.r", *ass, -1, new_position, 2);
								}
							}    

							if(new_position != -1)
								position = new_position;
						}
						emit("push.i", -1, -1, position, 1);
					}
					help_exp.erase(help_exp.end() - num_args, help_exp.end());
					for(ass = help_exp.begin(); ass != help_exp.end(); ass++)
					{
						//cout << symtable[*ass].name <<" po "<<endl;
					}
					int result = add_temptotable(symtable[yyvsp[-3]].vtype);
					emit("push.i", -1, -1, result, 1);
					incsp += 4;
					yyval = result;
					emit(string("call.i"), -1, -1, yyvsp[-3], 1);
					emit(string("incsp.i"), -1, -1, addtotable(to_string(incsp), INT), 1);
				}
			}
#line 1936 "parsertab.cpp"
    break;

  case 62: /* factor: NUMBER  */
#line 646 "parser.y"
                {          
			yyval = yyvsp[0]; 
		}
#line 1944 "parsertab.cpp"
    break;

  case 63: /* factor: '(' expression ')'  */
#line 650 "parser.y"
                {
			yyval = yyvsp[-1];
		}
#line 1952 "parsertab.cpp"
    break;

  case 64: /* factor: NOT factor  */
#line 653 "parser.y"
                        {
						if (symtable[yyvsp[0]].vtype == REA)
						{
							int temp = add_temptotable(INT);
							emit(string("realtoint.r"), yyvsp[0], -1, temp, 2);
							yyvsp[0] = temp;
						}
						int jump_label = addlabel();
						int false_number = addtotable("0", INT);
						emit(string("je.i"),yyvsp[0],false_number,jump_label,3);
						int sjump_label = addlabel();
						int temp_neg = add_temptotable(INT);
						gencode('=',false_number,-1,symtable[temp_neg].name);
						emit(string("jump.i"), -1,-1,sjump_label,1);
						
						emit(symtable[jump_label].name+string(":"),-1,-1,-1,0);
						int true_number = addtotable("1", INT);
						gencode('=',true_number,-1,symtable[temp_neg].name);
						
						emit(symtable[sjump_label].name+string(":"),-1,-1,-1,0);
						yyval = temp_neg;
						
					}
#line 1980 "parsertab.cpp"
    break;


#line 1984 "parsertab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 677 "parser.y"

void gencode(char op, int arg1, int arg2, string tname)
{

	switch(op)
	{
		case 'o':
			emit(string("or")+determine_type(arg1),arg1 , arg2 , lookup(tname) ,3); 
			break;
		case 'a':
			emit(string("and")+determine_type(arg1),arg1 , arg2 , lookup(tname) ,3); 
			break;			
		case '+':
			//cout << newtemp.name;
			emit(string("add")+determine_type(arg1),arg1 , arg2 , lookup(tname) ,3); 
			break;
		case '-':
			emit(string("sub")+determine_type(arg1),arg1 , arg2 , lookup(tname) ,3); 
			break;
		case '*':
			emit(string("mul")+determine_type(arg1),arg1 , arg2 , lookup(tname) ,3); 
			break;
		case '/':
			emit(string("div")+determine_type(arg1),arg1 , arg2 , lookup(tname) ,3);
			break; 
		case '=':
			emit(string("mov")+determine_type(arg1),arg1,-1,lookup(tname) ,2);
			break;
		case '%':
			emit(string("mod")+determine_type(arg1),arg1 , arg2 , lookup(tname) ,3); 
			break;
		default:
			return;
	}
}
int add_referencetotable(ValueType vtype, int cont,int offs)
{
	return addreferancetotable(vtype, cont,offs);
}
int addlabel()
{
	return addlabeltotable();
}
int add_temptotable(ValueType vtype)
{
	std::ostringstream oss;
	oss << "t" << tempno; 
	string temp = oss.str();
	int position = -1;
	if(context == 1)
		position = addtotable(temp,vtype,IDENTIFIER);
	else
	{
		if(vtype == REA)
			negoffset -=8;
		else
			negoffset -=4;
		position = addtotable(temp,vtype,IDENTIFIER,localcontext,negoffset);
	}
	tempno++;
	return position;
}
int convert_to_propertype(int arg1,int arg2)
{
	int position = -1;
	if((symtable[arg1].vtype == INT && symtable[arg2].vtype == INT)||(symtable[arg1].vtype == REA && symtable[arg2].vtype == REA))
	{
		return position;
	}
	else
	{
		position = add_temptotable(REA);
		if(symtable[arg1].vtype == INT && symtable[arg2].vtype == REA)
			emit(string("inttoreal.i"), arg1, -1, position, 2);
		else
			emit(string("inttoreal.i"), arg2, -1, position, 2);
	}
	return position;
}
int convert_to_assignment(int lside, int assignment)
{
	if(symtable[lside].vtype == symtable[assignment].vtype)
		return -1;
	if(symtable[lside].vtype == INT)
	{
		int position = add_temptotable(INT);
		emit(string("realtoint.r"), assignment, -1, position, 2);
		return position;
	}
	else
	{
		int position = add_temptotable(REA);
		emit(string("inttoreal.i"), assignment, -1, position, 2);
		return position;
	}
}
string determine_type(int arg1)
{
	if(symtable[arg1].vtype == INT)
		return string(".i ");
	else
		return string(".r ");
}
void emit(string command, int arg1, int arg2, int output, int arg_count)
{
    string instruction;

    if (arg_count == 0)
    {
        instruction = command + "\n";
        if(context == 1)
			cout << instruction;
        else
            function_body.push_back(instruction);
        return;
    }
    SymbolType type = symtable[output].type;
    int offset = symtable[output].offset;
	
    if (arg_count == 1)
    {
        if (symtable[output].type == NUM || symtable[output].type == LABEL || symtable[output].type == FUNC)
            instruction = command + "  #" + symtable[output].name + "\n";
        else
        {
            instruction = command + " " + determine_offset(output,command) + "\n";
        }
        if(context == 1)
			cout << "\t"+instruction;
        else 
            function_body.push_back(instruction);

        return;
    }

    instruction = command + " ";

    if (symtable[arg1].type == NUM || symtable[arg1].type == LABEL)
        instruction += "#" + symtable[arg1].name;
    else
        instruction += determine_offset(arg1,command);

    instruction += ", ";

    if (arg_count == 2)
    {
        if (type == LABEL)
            instruction += "#"+ symtable[output].name + "\n";
        else
            instruction += determine_offset(output,command)  + "\n";
        if(context == 1)
			cout << "\t"+instruction;
        else
            function_body.push_back(instruction);
        return;
    }

    if (arg_count == 3)
    {
        if (symtable[arg2].type == NUM || symtable[arg2].type == LABEL)
            instruction += "#" + symtable[arg2].name;
        else
            instruction += determine_offset(arg2,command); 

        if (type == LABEL || type == FUNC)
            instruction += ", #" + symtable[output].name + "\n";
        else
            instruction += ", " + determine_offset(output,command)  + "\n";
		if(context == 1)
			cout<<"\t"+instruction;
		else	
            function_body.push_back(instruction);

        return;
    }
}
string determine_offset(int ind,string command )
{
	if(symtable[ind].context == 1)
	{	
		if(command.find("push") != string::npos && symtable[ind].type != REFERENCE)
			return string("#"+to_string(symtable[ind].offset));
		if(command.find("push") != string::npos && symtable[ind].type == REFERENCE)
			return string(to_string(symtable[ind].offset));
		if(symtable[ind].type == REFERENCE && addressReference == true)
		{
			addressReference = false;
			return string(to_string(symtable[ind].offset));
		}
		else if(symtable[ind].type == REFERENCE)
		{
			return string("*"+to_string(symtable[ind].offset));
		}
		else
			return to_string(symtable[ind].offset);
	}
	else
	{
		if(symtable[ind].offset >0)
		{
			if(symtable[ind].type == REFERENCE)
			{
				if(command.find("push") != string::npos && symtable[ind].type == REFERENCE)
					return string("BP+")+to_string(symtable[ind].offset);
				if(addressReference == true)
				{
					addressReference = false;
					return string("BP+")+to_string(symtable[ind].offset);
				}
				else
					return string("*BP+")+to_string(symtable[ind].offset);
			}
			if(symtable[ind].type == FUNC )
				return string("*BP+")+to_string(symtable[ind].offset);
			else if(symtable[ind].type == IDENTIFIER && addressReference == false)
			{
				return string("BP+")+to_string(symtable[ind].offset);
			}
			else
				return string("*BP+")+to_string(symtable[ind].offset);
		}
		else
		{	
			if(command.find("push") != string::npos && symtable[ind].type == REFERENCE)
				return string("BP")+to_string(symtable[ind].offset);
			else if(command.find("push") != string::npos && symtable[ind].type != REFERENCE)
				return string("#BP")+to_string(symtable[ind].offset);
			if(symtable[ind].type == REFERENCE && addressReference == true)
			{
				addressReference = false;
				return string("BP")+to_string(symtable[ind].offset);
			}
			else if(symtable[ind].type == REFERENCE)
			{
				return string("*BP")+to_string(symtable[ind].offset);				
			}
			else 
				return string("BP")+to_string(symtable[ind].offset); 
		}
	}
}
void printAndClearFunctionBody() {
	string enterInstruction = "enter.i #" + to_string(count_enter(localcontext)) + "\n";
	function_body.insert(function_body.begin(), enterInstruction);
	function_body.push_back(string("leave\n"));
	function_body.push_back(string("return\n"));
    for (const string &instr : function_body) {
		if(instr.find(":") != string::npos)
			cout << instr;
        else
			cout << string("\t")+instr;
    }
    function_body.clear();
}

void yyerror(const char *s) {
    extern char *yytext;   
    cerr << "Błąd składni: " << s << " w linii " << lineno << " przy tokenie: " << yytext << endl;
}

