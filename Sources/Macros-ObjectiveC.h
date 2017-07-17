//  MIT License
//
//  Copyright (c) 2017 Lucas Stomberg
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of this software
//  and associated documentation files (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge, publish, distribute,
//  sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all copies or
//  substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//  BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//  DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#ifndef Macros_ObjectiveC_h
#define Macros_ObjectiveC_h

#define PTKStandardExecutionDetails [NSString stringWithFormat:@"%s [%s:%i]",__PRETTY_FUNCTION__, __FILE__, __LINE__]

#define TICK(taskName,segmentName,moduleName) \
    [[PTKPerformanceLog defaultLog] beginTask:^(PTKTaskConfiguration *config){ \
        config.identifiers.name = @"" # taskName; \
        config.identifiers.segment = @"" # segmentName; \
        config.identifiers.module = @"" # moduleName; \
        config.executionDetails = PTKStandardExecutionDetails; \
    } completion:nil]

#define TOCK(taskName,segmentName,moduleName,grouper) \
    [[PTKPerformanceLog defaultLog] endTask:({ \
        PTKTaskIdentifiers *identifiers = [PTKTaskIdentifiers new]; \
        identifiers.name = @"" # taskName; \
        identifiers.segment = @"" # segmentName; \
        identifiers.module = @"" # moduleName;  \
    identifiers; }) additionalGrouper:grouper]



#endif /* Macros_ObjectiveC_h */
