Gtest/Gmock and a Singleton
===========================

In my work, we have a few C++ classes that are impelemnted as (very strict)
singletons.  We've recently started to implement unit testing on top of this
code base.  After doing some reading, it seems that actually mocking singletons
can be difficult, if not impossible.  The general consensus seems to be that
singletons are evil and prevent unit testing.

Although part of me agrees with this, I do not have the ability to make the
changes necessary to remove these singletons.  Instead, we must somehow
work around the fact that these singletons exist in our unit testing.  The
current approach is to create a duplicated header for each class which looks
exactly like the real header, but contains the mock implementation.  I'm
wondering if there's a better way.

What's in here?
---------------

This is a small playground for me to come up with a better way to mock a
singleton.  The basis of the singleton implementation is contained in
MySingleton.h/.cpp.  This is the class I would like to mock, and it CANNOT be
modified to support unit testing.

The basic user class is `DependsOnSingleton`, and a basic unit test exists in
`TestDependsOnSingleton`.

Current Approach
----------------

The current approach is seen in MockMySingleton.h/.cpp.  This creates a new
abstraction layer (which is a "soft" singleton, out of necessity) that will sit
underneath the existing singleton.

So, `MySingleton` is what's called, which redirects to `SingletonAbstraction`,
which is the implementation of the mock.  In testing, we first create a
SingletonAbstraction object (on the stack!), then set the static `abstraction`
pointer to point to this object.

Now, we can set up all our expectations on this stack-allocated object, and the
singleton implementation (in `MockMySingleton`) will redirect there.

Is this better?
---------------

I'm not sure.  We're *still* maintaining extra files (which isn't ideal), but we
should get better error messages if a method is added to MySingleton.
Unfortunately, we still need to deal with any class-scoped static variables,
which is something I was hoping to avoid.

Overall, this is definitely still not perfect, but I think it's closer to an
ideal solution.  The ideal solution, of course, would be to remove the singleton
pattern and implement dependency injection to properly enable unit testing.
