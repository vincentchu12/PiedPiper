.class public if_elif_else
.super java/lang/Object

.field private static _runTimer LRunTimer;
.field private static _standardIn LPascalTextIn;
.field private static a I

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
	putstatic        if_elif_else/_runTimer LRunTimer;
	new PascalTextIn
	dup
	invokenonvirtual PascalTextIn/<init>()V
	putstatic        if_elif_else/_standardIn LPascalTextIn;
	ldc	3
	putstatic	if_elif_else/a I
	getstatic	if_elif_else/a I
	ldc	3
	if_icmplt Label_0
	getstatic	if_elif_else/a I
	ldc	3
	if_icmpeq Label_1
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc	"a is greater than 3"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	goto Label_2
Label_0:
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc	"a is less than 3"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	goto Label_2
Label_1:
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc	"a is equal to 3"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	goto Label_2
Label_2:

	getstatic     if_elif_else/_runTimer LRunTimer;
	invokevirtual RunTimer.printElapsedTime()V

	return

.limit locals 16
.limit stack 16
.end method
