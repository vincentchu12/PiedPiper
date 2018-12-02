.class public input
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
	putstatic        input/_runTimer LRunTimer;
	new PascalTextIn
	dup
	invokenonvirtual PascalTextIn/<init>()V
	putstatic        input/_standardIn LPascalTextIn;
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc	"%X"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	ldc	2
	ldc	3
	if_icmplt Label_0
	goto Label_1
Label_0:
	ldc	3
	putstatic	input/a I
	goto Label_1
Label_1:

	getstatic     input/_runTimer LRunTimer;
	invokevirtual RunTimer.printElapsedTime()V

	return

.limit locals 16
.limit stack 16
.end method
