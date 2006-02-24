# Configure paths for Ming
# Sandro Santilli 2006-01-24
#
# This macro uses ming-config, which was
# not available as for Ming 0.3beta1
#
#
#
# Use: 
#	AC_PATH_MING
#
# Provides:
#	MING_CFLAGS
#	MING_LIBS
#	MAKESWF
#

AC_DEFUN([GNASH_PATH_MING],
[
	MING_CFLAGS=""
	MING_LIBS=""

	AC_ARG_WITH(ming,[  --with-ming=[<ming-config>]    Use ming to build tests],
		[
		case "${withval}" in
			yes|no)
				;;
			*) MING_CONFIG=${withval}
				;;
		esac
		], MING_CONFIG="")

	if test x"$MING_CONFIG" = "x"; then
		AC_PATH_PROG(MING_CONFIG, ming-config)
	fi

	if test x"$MING_CONFIG" != "x"; then
		MING_CFLAGS=`$MING_CONFIG --cflags`
		MING_LIBS=`$MING_CONFIG --libs`
		MING_PATH=`$MING_CONFIG --bindir`
		AC_PATH_PROG([MAKESWF], [makeswf], , [$PATH:$MING_PATH])
	fi


	AC_SUBST(MING_CFLAGS)
	AC_SUBST(MING_LIBS)
	AC_SUBST(MAKESWF)
])
