#  cmakeLists.txt; 
#
#  Author(s): Ahmed Bachir <albachirou@gmail.com>
#             Kyoshe Winstone <wkyoshe@gmail.com>
#       Date: 2015-07-20
#
#  Université de Strasbourg.
#
# Distributed under the GPL(GNU Public License):
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#

SET(SRC
  02-environment
  03-mymesh
  04-myexpression
  #05-myexporter
  07-myfunctionspace
  08-myintegrals
  #  model1.cpp
  #  model2.cpp
  #  myadvection.cpp
  #  myappwithoptions.cpp
  #  mybackend.cpp
  #  myfunctor.cpp
  #  mylaplacian.cpp
  #  mymeshfromstring.cpp
  #  mystokes.cpp
  )
foreach(app ${SRC})
  if ( EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${app}.cfg AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${app}.geo )
    feelpp_add_application( ${app} SRCS ${app}.cpp  CFG ${app}.cfg GEO ${app}.geo)
  elseif ( EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${app}.cfg )
    feelpp_add_application( ${app} SRCS ${app}.cpp  CFG ${app}.cfg )
  else()
    feelpp_add_application( ${app} SRCS ${app}.cpp )
  endif()
endforeach()
