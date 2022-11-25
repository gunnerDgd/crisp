#pragma once
#include "../base/type_atomic.h"
#include "../base/type_primitive.h"
#include "../base/type_allocator.h"

#include <queue/queue.h>
#include <queue/queue_controller.h>

typedef __queue_node   __spsc_node;
typedef __queue_head   __spsc_head;
typedef __queue_entity __spsc_entity;