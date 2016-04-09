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
#line 32 "parser/parser.yy" // lalr1.cc:413

	#include <iostream>
	#include <cstdlib>
	#include <fstream>
	#include <math.h>
   
	#include "driver.hpp"
	#include "../include/variable.hpp"
	#include "../include/affectation.hpp"
	#include "../include/expression.hpp"
	#include "../include/comparatorFactory.hpp"
	#include "../include/block.hpp"
	#include "../include/ifElse.hpp"

	#undef yylex
	#define yylex scanner.yylex
	
	

#line 73 "parser/parser.cc" // lalr1.cc:413


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
#line 159 "parser/parser.cc" // lalr1.cc:479

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
#line 94 "parser/parser.yy" // lalr1.cc:859
    { ; }
#line 602 "parser/parser.cc" // lalr1.cc:859
    break;

  case 3:
#line 95 "parser/parser.yy" // lalr1.cc:859
    { ; }
#line 608 "parser/parser.cc" // lalr1.cc:859
    break;

  case 4:
#line 96 "parser/parser.yy" // lalr1.cc:859
    { ; }
#line 614 "parser/parser.cc" // lalr1.cc:859
    break;

  case 5:
#line 100 "parser/parser.yy" // lalr1.cc:859
    { ; }
#line 620 "parser/parser.cc" // lalr1.cc:859
    break;

  case 6:
#line 101 "parser/parser.yy" // lalr1.cc:859
    { 
		driver.block();
		Block * b = driver.currentBlock();
		if (b != nullptr) {
			b->add((yystack_[0].value.exprValue));
		} 
	}
#line 632 "parser/parser.cc" // lalr1.cc:859
    break;

  case 7:
#line 111 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.doubleValue) = -(yystack_[0].value.doubleValue); free((yystack_[1].value.stringValue)); }
#line 638 "parser/parser.cc" // lalr1.cc:859
    break;

  case 8:
#line 112 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.doubleValue) = (yystack_[0].value.doubleValue); free((yystack_[1].value.stringValue)); }
#line 644 "parser/parser.cc" // lalr1.cc:859
    break;

  case 9:
#line 113 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.doubleValue) = (yystack_[0].value.doubleValue); }
#line 650 "parser/parser.cc" // lalr1.cc:859
    break;

  case 10:
#line 117 "parser/parser.yy" // lalr1.cc:859
    { 
		(yylhs.value.exprValue) = driver.affectation((yystack_[0].value.exprValue), (yystack_[2].value.stringValue), (yystack_[1].value.stringValue));
		free((yystack_[1].value.stringValue));
		free((yystack_[2].value.stringValue));
	}
#line 660 "parser/parser.cc" // lalr1.cc:859
    break;

  case 11:
#line 122 "parser/parser.yy" // lalr1.cc:859
    { 
		(yylhs.value.exprValue) = driver.affectation((yystack_[0].value.exprValue), (yystack_[2].value.stringValue), (yystack_[1].value.stringValue));
		free((yystack_[1].value.stringValue));
		free((yystack_[2].value.stringValue));
	}
#line 670 "parser/parser.cc" // lalr1.cc:859
    break;

  case 12:
#line 130 "parser/parser.yy" // lalr1.cc:859
    { 
		(yylhs.value.exprValue) = driver.ternary((yystack_[5].value.exprValue), (yystack_[2].value.exprValue), (yystack_[0].value.exprValue));
	}
#line 678 "parser/parser.cc" // lalr1.cc:859
    break;

  case 13:
#line 136 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.exprValue) = driver.comp((yystack_[2].value.exprValue), (yystack_[0].value.exprValue), (yystack_[1].value.stringValue)); free((yystack_[1].value.stringValue)); }
#line 684 "parser/parser.cc" // lalr1.cc:859
    break;

  case 14:
#line 137 "parser/parser.yy" // lalr1.cc:859
    {
		ComparatorFactory * tmp = (ComparatorFactory *)(yystack_[1].value.exprValue);
		tmp->isNegation();
		(yylhs.value.exprValue) = tmp; 
	}
#line 694 "parser/parser.cc" // lalr1.cc:859
    break;

  case 15:
#line 142 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.exprValue) = (yystack_[1].value.exprValue); }
#line 700 "parser/parser.cc" // lalr1.cc:859
    break;

  case 16:
#line 143 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.exprValue) = driver.constant(0); }
#line 706 "parser/parser.cc" // lalr1.cc:859
    break;

  case 17:
#line 144 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.exprValue) = driver.constant(1); }
#line 712 "parser/parser.cc" // lalr1.cc:859
    break;

  case 18:
#line 148 "parser/parser.yy" // lalr1.cc:859
    { driver.ifElse((yystack_[8].value.exprValue), driver.previousBlock(), driver.currentBlock()); }
#line 718 "parser/parser.cc" // lalr1.cc:859
    break;

  case 19:
#line 152 "parser/parser.yy" // lalr1.cc:859
    { ; }
#line 724 "parser/parser.cc" // lalr1.cc:859
    break;

  case 20:
#line 153 "parser/parser.yy" // lalr1.cc:859
    { ; }
#line 730 "parser/parser.cc" // lalr1.cc:859
    break;

  case 21:
#line 157 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.exprValue) = driver.binop((yystack_[2].value.exprValue), (yystack_[0].value.exprValue), (yystack_[1].value.stringValue)); free((yystack_[1].value.stringValue)); }
#line 736 "parser/parser.cc" // lalr1.cc:859
    break;

  case 22:
#line 158 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.exprValue) = driver.binop((yystack_[2].value.exprValue), (yystack_[0].value.exprValue), (yystack_[1].value.stringValue)); free((yystack_[1].value.stringValue)); }
#line 742 "parser/parser.cc" // lalr1.cc:859
    break;

  case 23:
#line 159 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.exprValue) = driver.binop((yystack_[2].value.exprValue), (yystack_[0].value.exprValue), (yystack_[1].value.stringValue)); free((yystack_[1].value.stringValue)); }
#line 748 "parser/parser.cc" // lalr1.cc:859
    break;

  case 24:
#line 160 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.exprValue) = driver.binop((yystack_[2].value.exprValue), (yystack_[0].value.exprValue), (yystack_[1].value.stringValue)); free((yystack_[1].value.stringValue)); }
#line 754 "parser/parser.cc" // lalr1.cc:859
    break;

  case 25:
#line 161 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.exprValue) = (yystack_[1].value.exprValue); }
#line 760 "parser/parser.cc" // lalr1.cc:859
    break;

  case 26:
#line 162 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.exprValue) = driver.unop((yystack_[1].value.exprValue), (yystack_[3].value.stringValue)); free((yystack_[3].value.stringValue)); }
#line 766 "parser/parser.cc" // lalr1.cc:859
    break;

  case 27:
#line 163 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.exprValue) = driver.constant((yystack_[0].value.doubleValue)); }
#line 772 "parser/parser.cc" // lalr1.cc:859
    break;

  case 28:
#line 164 "parser/parser.yy" // lalr1.cc:859
    { (yylhs.value.exprValue) = driver.variable((yystack_[0].value.stringValue)); free((yystack_[0].value.stringValue)); }
#line 778 "parser/parser.cc" // lalr1.cc:859
    break;


#line 782 "parser/parser.cc" // lalr1.cc:859
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


  const signed char Parser::yypact_ninf_ = -16;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
      40,   -16,    -4,    19,    60,   -16,   -16,   -16,    46,   -16,
     -16,    -6,    -1,    19,     5,    18,   -16,   -16,   -16,    30,
      69,   -16,   -16,    19,   -16,    75,    53,    19,    31,    16,
     -16,   -16,    64,    53,    53,    53,    53,    53,    44,    53,
      55,    63,   -16,   -16,    68,    75,   -15,   -15,    61,    61,
      76,    62,   -16,   -16,   -16,     2,    53,    78,   -16,    -9,
      81,    53,    68,    75,    15,   -16
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,     5,     0,     0,     0,     3,     6,     4,     0,     9,
      28,     0,     0,     0,     0,     0,    16,    17,    27,     0,
       0,     1,     2,     0,    11,    10,     0,     0,     0,     0,
       8,     7,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    15,    25,     0,    13,    21,    22,    23,    24,
       0,     0,    26,    14,    20,     0,     0,     0,    19,     0,
       0,     0,     0,    12,     0,    18
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -16,   -16,     0,   -16,   -16,   -16,    43,   -16,    32,    -7
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     4,    54,    18,     6,    24,    19,     7,    55,    20
  };

  const unsigned char
  Parser::yytable_[] =
  {
       5,    25,    61,     8,    22,     1,    29,     2,    36,    30,
      26,    37,    34,    35,    36,    27,    29,    37,     1,    40,
       2,    57,    31,     9,    10,    11,    45,    46,    47,    48,
      49,    12,    51,    43,    65,    13,    33,    34,    35,    36,
      14,    15,    37,     1,    32,     2,    16,    17,    42,    59,
       9,    10,    11,     3,    63,    58,    28,     9,    10,    11,
      21,    50,    23,     1,    58,     2,    38,    14,    15,    39,
      41,     1,    52,     2,    14,    15,    34,    35,    36,    43,
      53,    37,    44,    34,    35,    36,    56,    37,    37,    33,
      34,    35,    36,    60,    64,    37,    34,    35,    36,    62,
       0,    37
  };

  const signed char
  Parser::yycheck_[] =
  {
       0,     8,    11,     7,     4,     3,    13,     5,    23,     4,
      16,    26,    21,    22,    23,    16,    23,    26,     3,    26,
       5,    19,     4,     4,     5,     6,    33,    34,    35,    36,
      37,    12,    39,    17,    19,    16,    20,    21,    22,    23,
      21,    22,    26,     3,    14,     5,    27,    28,    17,    56,
       4,     5,     6,    13,    61,    55,    13,     4,     5,     6,
       0,    17,    16,     3,    64,     5,    23,    21,    22,    16,
      27,     3,    17,     5,    21,    22,    21,    22,    23,    17,
      17,    26,    18,    21,    22,    23,    10,    26,    26,    20,
      21,    22,    23,    15,    62,    26,    21,    22,    23,    18,
      -1,    26
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     3,     5,    13,    30,    31,    33,    36,     7,     4,
       5,     6,    12,    16,    21,    22,    27,    28,    32,    35,
      38,     0,    31,    16,    34,    38,    16,    16,    35,    38,
       4,     4,    14,    20,    21,    22,    23,    26,    35,    16,
      38,    35,    17,    17,    18,    38,    38,    38,    38,    38,
      17,    38,    17,    17,    31,    37,    10,    19,    31,    38,
      15,    11,    18,    38,    37,    19
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    29,    30,    30,    30,    31,    31,    32,    32,    32,
      33,    33,    34,    35,    35,    35,    35,    35,    36,    37,
      37,    38,    38,    38,    38,    38,    38,    38,    38
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     1,     2,     2,     1,
       3,     3,     7,     3,     4,     3,     1,     1,    10,     2,
       1,     3,     3,     3,     3,     3,     4,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "EOL", "DOUBLE", "IDENTIFIER",
  "UNOP", "OA", "COMMA", "DEL", "IM", "OR", "EM", "IF", "THEN", "ELSE",
  "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "COMP", "ADD", "SUB",
  "BINOPMQ", "MINUS", "PLUS", "EXP", "\"0\"", "\"1\"", "$accept", "prog",
  "line", "number", "affectation", "ternary", "conditional", "ifElse",
  "block", "expression", YY_NULLPTR
  };


  const unsigned char
  Parser::yyrline_[] =
  {
       0,    94,    94,    95,    96,   100,   101,   111,   112,   113,
     117,   122,   130,   136,   137,   142,   143,   144,   148,   152,
     153,   157,   158,   159,   160,   161,   162,   163,   164
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
      25,    26,    27,    28
    };
    const unsigned int user_token_number_max_ = 283;
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
#line 1153 "parser/parser.cc" // lalr1.cc:1167
#line 167 "parser/parser.yy" // lalr1.cc:1168


void Algebra::Parser::error(const location_type & l, const std::string & err_message)
{
	std::cerr << "Error: " << err_message << " at line " << l << "\n";
}
