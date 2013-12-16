oclint-cocoa-additions
======================

This repository contains a number of conveniences for using OCLint[http://oclint.org] alongside Cocoa and Cocoa Touch.

Several of the checks included with OCLint allow you to annotate your code to achieve additional safety customized to your code base. Essentially, this mechanism allows oclint to add powerful static features to Objective-C, like protected methods and abstract methods that must be overriden by subclasses.

This repo contains some conveniences for utilizing these checks as well as annotations for some of the system frameworks that take advantage of these checks to formalize previously informal documentation.

# Usage #

## Adding to your project ##

There are three steps to adding these checks to your project so oclint can see them:

1. Check out this repo somewhere in your project directory hierarchy.
2. Add the ``OCLint-Annotations.h`` file to your Xcode project. You should probably ``#import`` it in in your project's ``.pch``, precompiled header file, so that it's visible to all your code.
3. Import other framework specific headers relevant to your project. For example, if you're using UIKit, add ``iOS/UIKit+OCLintStaticChecks.h`` wherever you include UIKit. The ``.pch`` file is a good place to put it if the system header for that framework is already there. But if you're including a system header only in certain cases, just make sure to include the associated OCLintStaticChecks file in addition to, or instead of, the library's standard header.

## Adding to your code ##

All of these checks work as annotations on method or property declarations. Furthmore, you can add annotations to already declared methods by redeclaring them in a category with the additional annotation. This is how the annotations included for system frameworks work.

These are also documented in ``OCLint-Annotations.h`` and you can look at the framework specific headers for examples.

For example, one of the checks allows you to declare that anyone overriding a method must call its super implemenation. This corresponds to the annotation ``__attribute__((annotate("oclint:enforce[must call super]")))``. But that is long, error prone, and hard to remember. Hence, ``OCLint-Annotations.h" contains the following macro:

```
#define OCLINT_MUST_CALL_SUPER __attribute__((annotate("oclint:enforce[must call super]")))
```

To use this you just add it to the end of your method declaration.

```
@interface SomeClass : NSObject

- (void)someMethod OCLINT_MUST_CALL_SUPER;

@end
```

If you do this and have a subclass that overrides ``someMethod`` but does not call ``[super someMethod]``, oclint will emit an error. If you deliberately don't want to call it, like in a base class implementation, you can suppress the violation using the standard oclint suppress mechanism. We provide some macros to make this convenient. For example:

```
@implementation SomeClass

- (void)someMethod OCLINT_SUPPRESS_MUST_CALL_SUPER {
    // don't call super because it's the base class
    ...
}

@end
```

# Rules

* OCLINT_MUST_CALL_SUPER, as previously discussed, allows you to mark a method as requiring a call to its super implementation. Some system framework methods are marked this way, even if the system superclass version is marked explicitly as not doing anything. This is to catch common cases, where subclasses farther down the hierarchy fail to call super. For example, it is a common mistake when dealing with deeper class hierarchies, for subclasses of subclasses of UIViewController to fail to call the super implementation of ``viewWillAppear:`` even though the implementation in UIViewController is documented to do nothing and so immediate subclasses don't really need to call super.

* OCLINT_PROTECTED_METHOD allows you to mark a method as protected. This is a concept from other OO languages (and also shows up as the little used ``@protected`` annotation on ivars). A protected method is a method that can only be called by the class itself and subclasses of that class.

* OCLINT_SUBCLASS_MUST_OVERRIDE allows you to mark a method that any subclass of the marked declaration's class must override. This is useful for implementing abstract classes.


Direct any questions to the [oclint google group](https://groups.google.com/forum/#!forum/oclint-users) or create an issue on github.
