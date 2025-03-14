# Duplicate and Index Items

## Examples

### [Program 4.12](./Examples/Program4_12/IndexedStack_IgnoreNew.c)

#### Stack with Index Items and an Ignore-the-New No Duplicates Policy

*This pushdown-stack implementation assumes that all items are integers between `0` and `maxN - 1`, so that it can maintain array `seen` that has a nonzero value correspondiing to each item in the stack. The array enables `STACKpush` to test quickly whether its argument is already on tthe stack, and to take no action if the test succeeds.*

*We update the [interface](./Examples/Program4_12/IndexedStack.h) to highlight we are explicitly using a index set.*

**Note:** We use only one bit per entry in `seen` so we could save space by using a `bit` array rather than an array of `bool` values.

## Exercises

