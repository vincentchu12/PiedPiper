.class public input
.super java/lang/Object

.field private static _runTimer LRunTimer;
.field private static _standardIn LPascalTextIn;
.field private static a [I
.field private static i I

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
	ldc	3
	newarray int
	putstatic	input/a [I
	getstatic	input/a [I
	ldc 0
	ldc	2
	iastore
	getstatic	input/a [I
	ldc 1
	ldc	3
	iastore
	getstatic	input/a [I
	ldc 2
	ldc	3
	iastore
	ldc	0
	putstatic	input/i I
Label_0:
	getstatic	input/i I
	ldc	3
	if_icmplt Label_1
	goto Label_2
Label_1:
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc	"%d"
	ldc	1
	anewarray java/lang/Object
	dup
	ldc	0
	getstatic	input/i I
	invokestatic java/lang/Integer.valueOf(I)Ljava/lang/Integer;
	aastore
	invokestatic  java/lang/String.format(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic	input/i I
	iconst_1
	iadd
	putstatic	input/i I
	goto Label_0
Label_2:

	getstatic     input/_runTimer LRunTimer;
	invokevirtual RunTimer.printElapsedTime()V

	return

.limit locals 16
.limit stack 16
.end method
