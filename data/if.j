.class public if
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
	putstatic        if/_runTimer LRunTimer;
	new PascalTextIn
	dup
	invokenonvirtual PascalTextIn/<init>()V
	putstatic        if/_standardIn LPascalTextIn;
	ldc	4
	putstatic	if/a I
	getstatic	if/a I
	ldc	5
	if_icmpne Label_0
	goto Label_1
Label_0:
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc	"a is not 5"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	goto Label_1
Label_1:

	getstatic     if/_runTimer LRunTimer;
	invokevirtual RunTimer.printElapsedTime()V

	return

.limit locals 16
.limit stack 16
.end method
