// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "parser/parser.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.h"

// User implementation prologue.

#line 51 "parser/parser.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 34 "parser/parser.yy" // lalr1.cc:413

	#include <iostream>
	#include <cstdlib>
	#include <fstream>
	#include <math.h>
	#include <list>
   
	#include "driver.hpp"
	#include "../include/variable.hpp"
	#include "../include/affectation.hpp"
	#include "../include/expression.hpp"
	#include "../include/comparatorFactory.hpp"
	#include "../include/block.hpp"
	#include "../include/ifElse.hpp"

	#undef yylex
	#define yylex scanner.yylex
	
	Block * block = nullptr;
	

#line 75 "parser/parser.cc" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "parser/parser.yy" // lalr1.cc:479
namespace Algebra {
#line 161 "parser/parser.cc" // lalr1.cc:479

  /// Build a parser object.
  Parser::Parser (Scanner & scanner_yyarg, Driver & driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  Parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  Parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  Parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  Parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  Parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  Parser::symbol_number_type
  Parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 101 "parser/parser.yy" // lalr1.cc:859
    { ; }
#line 604 "parser/parser.cc" // lalr1.cc:859
    break;

  case 3:
#line 102 "parser/parser.yy" // lalr1.cc:859
    { ; }
#line 610 "parser/parser.cc" // lalr1.cc:859
    break;

  case 4:
#line 103 "parser/parser.yy" // lalr1.cc:859
    { ; }
#line 616 "parser/parser.cc" // lalr1.cc:859
    break;

  case 5:
#line 107 "parser/parser.yy" // lalr1.cc:859
    { ; }
#line 622 "parser/parser.cc" // lalr1.cc:859
    break;

  case 6:
#line 108 "parser/parser.yy" // lalr1.cc:859
    { ; }
#line 628 "parser/parser.cc" // lalr1.cc:859
    break;

  case 7:
#line 109 "parser/parser.yy" // lalr1.cc:859
    { ; }
#line 634 "parser/parser.cc" // lalr1.cc:859
    break;

  case 8:
#line 113 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.doubleValue) = -(yystack_[0].value.doubleValue); free((yystack_[1].value.stringValue)); }
#line 640 "parser/parser.cc" // lalr1.cc:859
    break;

  case 9:
#line 114 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.doubleValue) = (yystack_[0].value.doubleValue); free((yystack_[1].value.stringValue)); }
#line 646 "parser/parser.cc" // lalr1.cc:859
    break;

  case 10:
#line 115 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.doubleValue) = (yystack_[0].value.doubleValue); }
#line 652 "parser/parser.cc" // lalr1.cc:859
    break;

  case 11:
#line 119 "parser/parser.yy" // lalr1.cc:859
    { 
		(yylhs.value.exprValue) = driver.affectation((yystack_[0].value.exprValue), (yystack_[2].value.stringValue), (yystack_[1].value.stringValue));
		free((yystack_[1].value.stringValue));
		free((yystack_[2].value.stringValue));
	}
#line 662 "parser/parser.cc" // lalr1.cc:859
    break;

  case 12:
#line 124 "parser/parser.yy" // lalr1.cc:859
    { 
		(yylhs.value.exprValue) = driver.affectation((yystack_[0].value.exprValue), (yystack_[2].value.stringValue), (yystack_[1].value.stringValue));
		free((yystack_[1].value.stringValue));
		free((yystack_[2].value.stringValue));
	}
#line 672 "parser/parser.cc" // lalr1.cc:859
    break;

  case 13:
#line 132 "parser/parser.yy" // lalr1.cc:859
    { 
		(yylhs.value.exprValue) = driver.ternary((yystack_[5].value.exprValue), (yystack_[2].value.exprValue), (yystack_[0].value.exprValue));
	}
#line 680 "parser/parser.cc" // lalr1.cc:859
    break;

  case 14:
#line 138 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.exprValue) = driver.comp((yystack_[2].value.exprValue), (yystack_[0].value.exprValue), (yystack_[1].value.stringValue)); free((yystack_[1].value.stringValue)); }
#line 686 "parser/parser.cc" // lalr1.cc:859
    break;

  case 15:
#line 139 "parser/parser.yy" // lalr1.cc:859
    {
		ComparatorFactory * tmp = (ComparatorFactory *)(yystack_[1].value.exprValue);
		tmp->isNegation();
		(yylhs.value.exprValue) = tmp; 
	}
#line 696 "parser/parser.cc" // lalr1.cc:859
    break;

  case 16:
#line 144 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.exprValue) = (yystack_[1].value.exprValue); }
#line 702 "parser/parser.cc" // lalr1.cc:859
    break;

  case 17:
#line 145 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.exprValue) = driver.constant(0); }
#line 708 "parser/parser.cc" // lalr1.cc:859
    break;

  case 18:
#line 146 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.exprValue) = driver.constant(1); }
#line 714 "parser/parser.cc" // lalr1.cc:859
    break;

  case 19:
#line 150 "parser/parser.yy" // lalr1.cc:859
    { 
		if (block == nullptr)
		{
			block = new Block();
		}
		block->add((Affectation*)(yystack_[0].value.exprValue)); 
		(yylhs.value.blockValue) = new Block(*block);
	}
#line 727 "parser/parser.cc" // lalr1.cc:859
    break;

  case 20:
#line 158 "parser/parser.yy" // lalr1.cc:859
    {
		if (block == nullptr)
		{
			block = new Block();
		}
		block->add((Affectation*)(yystack_[0].value.exprValue));
		(yylhs.value.blockValue) = new Block(*block);
	}
#line 740 "parser/parser.cc" // lalr1.cc:859
    break;

  case 21:
#line 169 "parser/parser.yy" // lalr1.cc:859
    { driver.ifElse((yystack_[4].value.exprValue), (yystack_[2].value.blockValue), (yystack_[0].value.blockValue)); }
#line 746 "parser/parser.cc" // lalr1.cc:859
    break;

  case 22:
#line 170 "parser/parser.yy" // lalr1.cc:859
    { driver.ifElse((yystack_[7].value.exprValue), (yystack_[4].value.blockValue), (yystack_[0].value.blockValue)); }
#line 752 "parser/parser.cc" // lalr1.cc:859
    break;

  case 23:
#line 171 "parser/parser.yy" // lalr1.cc:859
    { driver.ifElse((yystack_[6].value.exprValue), (yystack_[4].value.blockValue), (yystack_[0].value.blockValue)); }
#line 758 "parser/parser.cc" // lalr1.cc:859
    break;

  case 24:
#line 172 "parser/parser.yy" // lalr1.cc:859
    { driver.ifElse((yystack_[3].value.exprValue), (yystack_[2].value.blockValue), (yystack_[0].value.blockValue)); }
#line 764 "parser/parser.cc" // lalr1.cc:859
    break;

  case 25:
#line 176 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.blockValue) = driver.block((yystack_[1].value.blockValue)); block = nullptr; }
#line 770 "parser/parser.cc" // lalr1.cc:859
    break;

  case 26:
#line 177 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.blockValue) = driver.block((yystack_[2].value.blockValue)); block = nullptr; }
#line 776 "parser/parser.cc" // lalr1.cc:859
    break;

  case 27:
#line 181 "parser/parser.yy" // lalr1.cc:859
    {
		driver.forLoop((Affectation *)(yystack_[6].value.exprValue), (ComparatorFactory*)(yystack_[4].value.exprValue), (Affectation *)(yystack_[2].value.exprValue), (yystack_[0].value.blockValue));
	}
#line 784 "parser/parser.cc" // lalr1.cc:859
    break;

  case 28:
#line 187 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.exprValue) = driver.binop((yystack_[2].value.exprValue), (yystack_[0].value.exprValue), (yystack_[1].value.stringValue)); free((yystack_[1].value.stringValue)); }
#line 790 "parser/parser.cc" // lalr1.cc:859
    break;

  case 29:
#line 188 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.exprValue) = driver.binop((yystack_[2].value.exprValue), (yystack_[0].value.exprValue), (yystack_[1].value.stringValue)); free((yystack_[1].value.stringValue)); }
#line 796 "parser/parser.cc" // lalr1.cc:859
    break;

  case 30:
#line 189 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.exprValue) = driver.binop((yystack_[2].value.exprValue), (yystack_[0].value.exprValue), (yystack_[1].value.stringValue)); free((yystack_[1].value.stringValue)); }
#line 802 "parser/parser.cc" // lalr1.cc:859
    break;

  case 31:
#line 190 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.exprValue) = driver.binop((yystack_[2].value.exprValue), (yystack_[0].value.exprValue), (yystack_[1].value.stringValue)); free((yystack_[1].value.stringValue)); }
#line 808 "parser/parser.cc" // lalr1.cc:859
    break;

  case 32:
#line 191 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.exprValue) = (yystack_[1].value.exprValue); }
#line 814 "parser/parser.cc" // lalr1.cc:859
    break;

  case 33:
#line 192 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.exprValue) = driver.unop((yystack_[1].value.exprValue), (yystack_[3].value.stringValue)); free((yystack_[3].value.stringValue)); }
#line 820 "parser/parser.cc" // lalr1.cc:859
    break;

  case 34:
#line 193 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.exprValue) = driver.constant((yystack_[0].value.doubleValue)); }
#line 826 "parser/parser.cc" // lalr1.cc:859
    break;

  case 35:
#line 194 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.exprValue) = driver.variable((yystack_[0].value.stringValue)); free((yystack_[0].value.stringValue)); }
#line 832 "parser/parser.cc" // lalr1.cc:859
    break;


#line 836 "parser/parser.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char Parser::yypact_ninf_ = -21;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
      42,   -21,    21,    60,   -14,    68,   -21,   -21,   -21,   -21,
      69,   -21,   -21,    -9,    18,    60,    30,    38,   -21,   -21,
     -21,    -2,    26,    41,   -21,    -3,    60,   -21,    99,    76,
      60,    33,    79,   -21,   -21,    37,     5,    10,    43,    76,
      76,    76,    76,    76,    46,   -21,    50,    76,    86,    66,
     -21,   -21,    83,    37,    80,    41,   -21,     3,    37,    99,
      63,    63,    78,    78,    60,    87,    93,   -21,   -21,    81,
     105,    37,   110,    41,   -21,   -21,   103,    76,   112,   111,
     -21,     2,   -21,    41,    16,    37,   117,   -21,   106,    76,
     -21,    37,    37,    99,   -21,   -21
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,     4,     0,     0,     0,     0,     3,     5,     6,     7,
       0,    10,    35,     0,     0,     0,     0,     0,    17,    18,
      34,     0,     0,     0,     1,     0,     0,    12,    11,     0,
       0,     0,     0,     9,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     0,     0,
      16,    32,     0,     0,     0,     0,    20,     0,     0,    14,
      28,    29,    30,    31,     0,     0,     0,    33,    15,     0,
       0,     0,     0,     0,    25,    24,     0,     0,     0,     0,
      21,     0,    19,     0,     0,     0,     0,    26,     0,     0,
      23,     0,     0,    13,    22,    27
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -21,   -21,   104,   -21,   -20,   -21,    -4,    73,   -21,   -15,
     -21,   -10
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     5,     6,    20,     7,    27,    21,    57,     8,    38,
       9,    22
  };

  const unsigned char
  Parser::yytable_[] =
  {
      28,    35,     2,    44,    23,    32,    73,     2,    53,    29,
       3,    31,    36,    55,     4,     2,    32,    56,    37,    48,
      52,    54,    46,    87,    74,    37,    49,    89,    10,    59,
      60,    61,    62,    63,    33,    56,    30,    66,    70,    40,
      41,    42,    34,    75,    43,     1,     2,     2,    39,    40,
      41,    42,    50,    82,    43,     3,    80,    37,    58,     4,
      76,    82,    64,    88,    11,    12,    13,    84,    24,    65,
      90,    25,    14,    11,    12,    13,    94,    95,    15,    93,
      11,    12,    13,    16,    17,    68,    69,    26,    42,    18,
      19,    43,    16,    17,    47,    71,    78,    77,    51,    16,
      17,    39,    40,    41,    42,    67,    43,    43,    79,    40,
      41,    42,    51,    81,    43,    85,    40,    41,    42,    83,
      91,    43,    40,    41,    42,    92,    86,    43,    72,    45
  };

  const unsigned char
  Parser::yycheck_[] =
  {
      10,     3,     5,    23,    18,    15,     3,     5,     3,    18,
      13,    15,    14,     3,    17,     5,    26,    37,    20,    29,
      35,    36,    26,    21,    21,    20,    30,    11,     7,    39,
      40,    41,    42,    43,     4,    55,    18,    47,    53,    23,
      24,    25,     4,    58,    28,     3,     5,     5,    22,    23,
      24,    25,    19,    73,    28,    13,    71,    20,    15,    17,
      64,    81,    16,    83,     4,     5,     6,    77,     0,    19,
      85,     3,    12,     4,     5,     6,    91,    92,    18,    89,
       4,     5,     6,    23,    24,    19,     3,    18,    25,    29,
      30,    28,    23,    24,    18,    15,    15,    10,    19,    23,
      24,    22,    23,    24,    25,    19,    28,    28,     3,    23,
      24,    25,    19,     3,    28,     3,    23,    24,    25,    16,
       3,    28,    23,    24,    25,    19,    15,    28,    55,    25
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     3,     5,    13,    17,    32,    33,    35,    39,    41,
       7,     4,     5,     6,    12,    18,    23,    24,    29,    30,
      34,    37,    42,    18,     0,     3,    18,    36,    42,    18,
      18,    37,    42,     4,     4,     3,    14,    20,    40,    22,
      23,    24,    25,    28,    35,    33,    37,    18,    42,    37,
      19,    19,    40,     3,    40,     3,    35,    38,    15,    42,
      42,    42,    42,    42,    16,    19,    42,    19,    19,     3,
      40,    15,    38,     3,    21,    40,    37,    10,    15,     3,
      40,     3,    35,    16,    42,     3,    15,    21,    35,    11,
      40,     3,    19,    42,    40,    40
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    31,    32,    32,    32,    33,    33,    33,    34,    34,
      34,    35,    35,    36,    37,    37,    37,    37,    37,    38,
      38,    39,    39,    39,    39,    40,    40,    41,    42,    42,
      42,    42,    42,    42,    42,    42
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     3,     1,     1,     1,     1,     1,     2,     2,
       1,     3,     3,     7,     3,     4,     3,     1,     1,     3,
       1,     6,     9,     8,     5,     3,     5,     9,     3,     3,
       3,     3,     3,     4,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "EOL", "DOUBLE", "IDENTIFIER",
  "UNOP", "OA", "COMMA", "DEL", "IM", "OR", "EM", "IF", "THEN", "ELSE",
  "SEMICOLON", "LOOP", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "COMP",
  "ADD", "SUB", "BINOPMQ", "MINUS", "PLUS", "EXP", "\"0\"", "\"1\"",
  "$accept", "prog", "line", "number", "affectation", "ternary",
  "conditional", "block", "ifElse", "braces", "loop", "expression", YY_NULLPTR
  };


  const unsigned char
  Parser::yyrline_[] =
  {
       0,   101,   101,   102,   103,   107,   108,   109,   113,   114,
     115,   119,   124,   132,   138,   139,   144,   145,   146,   150,
     158,   169,   170,   171,   172,   176,   177,   181,   187,   188,
     189,   190,   191,   192,   193,   194
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
    };
    const unsigned int user_token_number_max_ = 285;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 5 "parser/parser.yy" // lalr1.cc:1167
} // Algebra
#line 1225 "parser/parser.cc" // lalr1.cc:1167
#line 197 "parser/parser.yy" // lalr1.cc:1168


void Algebra::Parser::error(const location_type & l, const std::string & err_message)
{
	std::cerr << "Error: " << err_message << " at line " << l << "\n";
}
