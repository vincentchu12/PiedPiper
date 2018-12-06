<<<<<<< HEAD
=======
.class public input
.super java/lang/Object

.field private static _runTimer LRunTimer;
.field private static _standardIn LPascalTextIn;
<<<<<<< HEAD
>>>>>>> 6363286... add functions
=======
.field private static b I
.field private static foo_a I
.field private static foo_b I

.method public <init>()V

	aload_0
	invokenonvirtual    java/lang/Object/<init>()V
	return

.limit locals 1
.limit stack 1
.end method

.method public static main([Ljava/lang/String;)V

	new RunTimer
	dup
	invokenonvirtual RunTimer/<init>()V
	putstatic        input/_runTimer LRunTimer;
	new PascalTextIn
	dup
	invokenonvirtual PascalTextIn/<init>()V
	putstatic        input/_standardIn LPascalTextIn;
	ldc	4
	putstatic	input/b I
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc	"hello"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	goto foo_end
foo:
	astore_1
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc	"goodbye"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic	input/foo_a I
	getstatic	input/foo_b I
	if_icmpeq Label_0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc	"no"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	goto Label_1
Label_0:
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc	"yes"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	goto Label_1
Label_1:
	ret 1
foo_end:
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc	"there"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	ldc	8
	putstatic	input/foo_a I
	ldc	9
	putstatic	input/foo_b I
	jsr foo

	getstatic     input/_runTimer LRunTimer;
	invokevirtual RunTimer.printElapsedTime()V

	return

.limit locals 16
.limit stack 16
.end method
>>>>>>> aab952d... Pass1 function declarations
