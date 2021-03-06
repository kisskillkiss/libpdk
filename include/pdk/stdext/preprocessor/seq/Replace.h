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
// Created by softboy on 2018/01/18.

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

#ifndef PDK_STDEXT_PREPROCESSOR_SEQ_REPLACE_H
#define PDK_STDEXT_PREPROCESSOR_SEQ_REPLACE_H

#include "pdk/stdext/preprocessor/arithmetic/Dec.h"
#include "pdk/stdext/preprocessor/arithmetic/Inc.h"
#include "pdk/stdext/preprocessor/config/Config.h"
#include "pdk/stdext/preprocessor/comparison/Equal.h"
#include "pdk/stdext/preprocessor/control/Iif.h"
#include "pdk/stdext/preprocessor/seq/FirstN.h"
#include "pdk/stdext/preprocessor/seq/RestN.h"
#include "pdk/stdext/preprocessor/seq/Size.h"

// PDK_PP_SEQ_REPLACE
# if ~PDK_PP_CONFIG_FLAGS() & PDK_PP_CONFIG_EDG()
#    define PDK_PP_SEQ_REPLACE(seq, i, elem) PDK_PP_SEQ_FIRST_N(i, seq) (elem) PDK_PP_SEQ_REPLACE_DETAIL_REST(seq, i)
# else
#    define PDK_PP_SEQ_REPLACE(seq, i, elem) PDK_PP_SEQ_REPLACE_I(seq, i, elem)
#    define PDK_PP_SEQ_REPLACE_I(seq, i, elem) PDK_PP_SEQ_FIRST_N(i, seq) (elem) PDK_PP_SEQ_REPLACE_DETAIL_REST(seq, i)
# endif
#
#    define PDK_PP_SEQ_REPLACE_DETAIL_REST_EMPTY(seq, i)
#    define PDK_PP_SEQ_REPLACE_DETAIL_REST_VALID(seq, i) PDK_PP_SEQ_REST_N(PDK_PP_INC(i), seq)
#    define PDK_PP_SEQ_REPLACE_DETAIL_REST(seq, i) \
		PDK_PP_IIF \
			( \
			PDK_PP_EQUAL(i,PDK_PP_DEC(PDK_PP_SEQ_SIZE(seq))), \
			PDK_PP_SEQ_REPLACE_DETAIL_REST_EMPTY, \
			PDK_PP_SEQ_REPLACE_DETAIL_REST_VALID \
			) \
		(seq, i) \
/**/

#endif // PDK_STDEXT_PREPROCESSOR_SEQ_REPLACE_H
