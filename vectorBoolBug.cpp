std::vector<bool> is not the same as a boolean array.  It optimizes storage, potentially leading to unexpected behavior when iterating or accessing elements.  For example, using normal array indexing might not work as expected, and using iterators can be more complex due to its custom implementation.  This optimization can significantly impact performance and correctness if not understood.