.class public input
.super java/lang/Object

.field private static _runTimer LRunTimer;
.field private static _standardIn LPascalTextIn;
.field private static arr [I
.field private static temp [I
.field private static idx I
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
	putstatic	input/arr [I
	getstatic	input/arr [I
	ldc 0
	ldc	1
	iastore
	getstatic	input/arr [I
	ldc 1
	ldc	2
	iastore
	getstatic	input/arr [I
	ldc 2
	ldc	3
	iastore
	ldc	3
	newarray int
	putstatic	input/temp [I
	ldc 0
	putstatic	input/idx I
Label_0:
	getstatic	input/idx I
	ldc 3
	if_icmplt Label_1
	goto Label_2
Label_1:
	ldc 3
	getstatic	input/arr [I
	getstatic	input/idx I
	aaload
	putstatic	input/val I
	getstatic	input/temp [I
	getstatic	input/idx I
	getstatic	input/val ?
	iastore
	getstatic	input/idx I
	iconst_1
	iadd
	putstatic	input/idx I
	goto Label_0
Label_2:

	getstatic     input/_runTimer LRunTimer;
	invokevirtual RunTimer.printElapsedTime()V

	return

.limit locals 16
.limit stack 16
.end method
