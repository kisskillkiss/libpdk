// @copyright 2017-2018 zzu_softboy <zzu_softboy@163.com>
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Created by softboy on 2018/01/15.

// ****************************************************************************
// *                                                                          *
// *     (C) Copyright Paul Mensonides 2002-2011.                             *
// *     (C) Copyright Edward Diener 2011.                                    *
// *     Distributed under the Boost Software License, Version 1.0. (See      *
// *     accompanying file LICENSE_1_0.txt or copy at                         *
// *     http://www.boost.org/LICENSE_1_0.txt)                                *
// *                                                                          *
// ****************************************************************************
// 
// See http://www.boost.org for most recent version.

#ifndef PDK_STDEXT_PREPROCESSOR_FACILITIES_EXPAND_H
#define PDK_STDEXT_PREPROCESSOR_FACILITIES_EXPAND_H

#include "pdk/stdext/preprocessor/config/Config.h"

# if ~PDK_PP_CONFIG_FLAGS() & PDK_PP_CONFIG_MWCC() && ~PDK_PP_CONFIG_FLAGS() & PDK_PP_CONFIG_DMC()
#    define PDK_PP_EXPAND(x) PDK_PP_EXPAND_I(x)
# else
#    define PDK_PP_EXPAND(x) PDK_PP_EXPAND_OO((x))
#    define PDK_PP_EXPAND_OO(par) PDK_PP_EXPAND_I ## par
# endif
#
# define PDK_PP_EXPAND_I(x) x

#endif // PDK_STDEXT_PREPROCESSOR_FACILITIES_EXPAND_H
