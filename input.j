.class public input
.super java/lang/Object

.field private static _runTimer LRunTimer;
.field private static _standardIn LPascalTextIn;
.field private static x [I
.field private static temp [I
.field private static i I
.field private static val I

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
	putstatic	input/x [I
	getstatic	input/x [I
	ldc 0
	ldc	1
	iastore
	getstatic	input/x [I
	ldc 1
	ldc	2
	iastore
	getstatic	input/x [I
	ldc 2
	ldc	3
	iastore
	ldc	3
	newarray int
	putstatic	input/temp [I
	ldc 0
	getstatic	input/[223 163 257 62] I
	iconst_1
	iadd
	putstatic	input/[223 163 257 62] I
	goto Label_0
Label_2:

	getstatic     input/_runTimer LRunTimer;
	invokevirtual RunTimer.printElapsedTime()V

	return

.limit locals 16
.limit stack 16
.end method
