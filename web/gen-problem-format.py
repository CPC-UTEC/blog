#!/usr/bin/python

import sys

if len(sys.argv) == 1:
    print("invalid usage")
    print("python program-name.py [id-problem]")
    sys.exit(-1)

id = sys.argv[1]
output = """
<!-- Begins problem %s -->
<div class="card" id="%s">
<div class="collapsed solution-title" type="button" data-toggle="collapse" data-target="#collapseProblem%s" aria-expanded="false" aria-controls="collapseTwo">
<!-- title -->
  <i class="fas fa-caret-right"></i> <p class="title">%s: [Title Name]</p>
</div>
<!-- begin body -->
<div id="collapseProblem%s" class="collapse">
<div class="card-body solution-body">

### <a href="[INSERT LINK!!!!]" target="_blank">Problem %s: [Title Name]</a>

[EXPLANATION]

  <!-- begin code -->
  <div class="collapsed code-title" type="button" data-toggle="collapse" data-target="#codeProblem%s" aria-expanded="false" aria-controls="collapseTwo">
  <!-- title -->
  <i class="fas fa-caret-right"></i> <p class="title">Code</p>
  </div>
  <div id="codeProblem%s" class="collapse">

```c++
// TO DO
```

  </div>
  <!-- ends code -->

</div>
</div>
</div>
<!-- ends problem %s -->

""" %(id, id, id, id, id, id, id, id, id)

print(output)
