#ifndef __OCLINT_ANNOTATIONS__
#define __OCLINT_ANNOTATIONS__


// All subclasses overriding this method should be calling super
#define OCLINT_MUST_CALL_SUPER __attribute__((annotate("oclint:enforce[must call super]")))
#define OCLINT_SUPPRESS_MUST_CALL_SUPER __attribute__((annotate("oclint:suppress[must call super]")))

// This method can only be called by the class declaring it or by subclasses of that class.
#define OCLINT_PROTECTED_METHOD __attribute__((annotate("oclint:enforce[protected method]")))
#define OCLINT_SUPPRESS_PROTECTED_METHOD __attribute__((annotate("oclint:suppress[protected method]")))

// This method must be implemented by subclasses of the class declaring it
#define OCLINT_SUBCLASS_MUST_IMPLEMENT __attribute__((annotate("oclint:enforce[subclass must implement]")))
#define OCLINT_SUPPRESS_SUBCLASS_MUST_IMPLEMENT __attribute__((annotate("oclint:suppress[subclass must implement]")))

#endif
