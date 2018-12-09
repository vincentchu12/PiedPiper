.class public for_iterator
.super java/lang/Object

.field private static _runTimer LRunTimer;
.field private static _standardIn LPascalTextIn;
.field private static a [I
.field private static idx I
.field private static val I
.field private static c [Ljava/lang/String;
.field private static index I
.field private static value Ljava/lang/String;

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
	putstatic        for_iterator/_runTimer LRunTimer;
	new PascalTextIn
	dup
	invokenonvirtual PascalTextIn/<init>()V
	putstatic        for_iterator/_standardIn LPascalTextIn;
	ldc	4
	newarray int
	putstatic	for_iterator/a [I
	getstatic	for_iterator/a [I
	ldc 0
	ldc	94
	iastore
	getstatic	for_iterator/a [I
	ldc 1
	ldc	127
	iastore
	getstatic	for_iterator/a [I
	ldc 2
	ldc	47
	iastore
	getstatic	for_iterator/a [I
	ldc 3
	ldc	298
	iastore
	ldc 0
	putstatic	for_iterator/idx I
Label_0:
	getstatic	for_iterator/idx I
	ldc 4
	if_icmplt Label_1
	goto Label_2
Label_1:
	getstatic	for_iterator/a [I
	getstatic	for_iterator/idx I
	iaload
	putstatic	for_iterator/val I
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc	"The value at index: %d is %d"
	ldc	2
	anewarray java/lang/Object
	dup
	ldc	0
	getstatic	for_iterator/idx I
	invokestatic java/lang/Integer.valueOf(I)Ljava/lang/Integer;
	aastore
	dup
	ldc	1
	getstatic	for_iterator/val I
	invokestatic java/lang/Integer.valueOf(I)Ljava/lang/Integer;
	aastore
	invokestatic  java/lang/String.format(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic	for_iterator/idx I
	iconst_1
	iadd
	putstatic	for_iterator/idx I
	goto Label_0
Label_2:
	ldc	4
	anewarray java/lang/String
	putstatic	for_iterator/c [Ljava/lang/String;
	getstatic	for_iterator/c [Ljava/lang/String;
	ldc 0
	ldc	"this"
	aastore
	getstatic	for_iterator/c [Ljava/lang/String;
	ldc 1
	ldc	"is"
	aastore
	getstatic	for_iterator/c [Ljava/lang/String;
	ldc 2
	ldc	"our"
	aastore
	getstatic	for_iterator/c [Ljava/lang/String;
	ldc 3
	ldc	"language"
	aastore
	ldc 0
	putstatic	for_iterator/index I
Label_3:
	getstatic	for_iterator/index I
	ldc 4
	if_icmplt Label_4
	goto Label_5
Label_4:
	getstatic	for_iterator/c [Ljava/lang/String;
	getstatic	for_iterator/index I
	aaload
	putstatic	for_iterator/value Ljava/lang/String;
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc	"The value at index: %d is %s"
	ldc	2
	anewarray java/lang/Object
	dup
	ldc	0
	getstatic	for_iterator/index I
	invokestatic java/lang/Integer.valueOf(I)Ljava/lang/Integer;
	aastore
	dup
	ldc	1
	getstatic	for_iterator/value Ljava/lang/String;
	aastore
	invokestatic  java/lang/String.format(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic	for_iterator/index I
	iconst_1
	iadd
	putstatic	for_iterator/index I
	goto Label_3
Label_5:

	getstatic     for_iterator/_runTimer LRunTimer;
	invokevirtual RunTimer.printElapsedTime()V

	return

.limit locals 16
.limit stack 16
.end method
