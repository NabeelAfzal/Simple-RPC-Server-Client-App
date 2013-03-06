/* Generated by the protocol buffer compiler.  DO NOT EDIT! */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C_NO_DEPRECATED
#define PROTOBUF_C_NO_DEPRECATED
#endif

#include "task.pb-c.h"
void   task__input__init
                     (Task__Input         *message)
{
  static Task__Input init_value = TASK__INPUT__INIT;
  *message = init_value;
}
size_t task__input__get_packed_size
                     (const Task__Input *message)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &task__input__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t task__input__pack
                     (const Task__Input *message,
                      uint8_t       *out)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &task__input__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t task__input__pack_to_buffer
                     (const Task__Input *message,
                      ProtobufCBuffer *buffer)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &task__input__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Task__Input *
       task__input__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Task__Input *)
     protobuf_c_message_unpack (&task__input__descriptor,
                                allocator, len, data);
}
void   task__input__free_unpacked
                     (Task__Input *message,
                      ProtobufCAllocator *allocator)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &task__input__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   task__output__init
                     (Task__Output         *message)
{
  static Task__Output init_value = TASK__OUTPUT__INIT;
  *message = init_value;
}
size_t task__output__get_packed_size
                     (const Task__Output *message)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &task__output__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t task__output__pack
                     (const Task__Output *message,
                      uint8_t       *out)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &task__output__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t task__output__pack_to_buffer
                     (const Task__Output *message,
                      ProtobufCBuffer *buffer)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &task__output__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Task__Output *
       task__output__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Task__Output *)
     protobuf_c_message_unpack (&task__output__descriptor,
                                allocator, len, data);
}
void   task__output__free_unpacked
                     (Task__Output *message,
                      ProtobufCAllocator *allocator)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &task__output__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor task__input__field_descriptors[3] =
{
  {
    "a",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(Task__Input, a),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "b",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(Task__Input, b),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "c",
    3,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(Task__Input, c),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned task__input__field_indices_by_name[] = {
  0,   /* field[0] = a */
  1,   /* field[1] = b */
  2,   /* field[2] = c */
};
static const ProtobufCIntRange task__input__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 3 }
};
const ProtobufCMessageDescriptor task__input__descriptor =
{
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  "Task.Input",
  "Input",
  "Task__Input",
  "Task",
  sizeof(Task__Input),
  3,
  task__input__field_descriptors,
  task__input__field_indices_by_name,
  1,  task__input__number_ranges,
  (ProtobufCMessageInit) task__input__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor task__output__field_descriptors[2] =
{
  {
    "Sum",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(Task__Output, sum),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "Product",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(Task__Output, product),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned task__output__field_indices_by_name[] = {
  1,   /* field[1] = Product */
  0,   /* field[0] = Sum */
};
static const ProtobufCIntRange task__output__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor task__output__descriptor =
{
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  "Task.Output",
  "Output",
  "Task__Output",
  "Task",
  sizeof(Task__Output),
  2,
  task__output__field_descriptors,
  task__output__field_indices_by_name,
  1,  task__output__number_ranges,
  (ProtobufCMessageInit) task__output__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCMethodDescriptor task__process__method_descriptors[2] =
{
  { "Add", &task__input__descriptor, &task__output__descriptor },
  { "Multiply", &task__input__descriptor, &task__output__descriptor },
};
const unsigned task__process__method_indices_by_name[] = {
  0,        /* Add */
  1         /* Multiply */
};
const ProtobufCServiceDescriptor task__process__descriptor =
{
  PROTOBUF_C_SERVICE_DESCRIPTOR_MAGIC,
  "Task.Process",
  "Multiply",
  "Task__Process",
  "Task",
  2,
  task__process__method_descriptors,
  task__process__method_indices_by_name
};
void task__process__add(ProtobufCService *service,
                        const Task__Input *input,
                        Task__Output_Closure closure,
                        void *closure_data)
{
  PROTOBUF_C_ASSERT (service->descriptor == &task__process__descriptor);
  service->invoke(service, 0, (const ProtobufCMessage *) input, (ProtobufCClosure) closure, closure_data);
}
void task__process__multiply(ProtobufCService *service,
                             const Task__Input *input,
                             Task__Output_Closure closure,
                             void *closure_data)
{
  PROTOBUF_C_ASSERT (service->descriptor == &task__process__descriptor);
  service->invoke(service, 1, (const ProtobufCMessage *) input, (ProtobufCClosure) closure, closure_data);
}
void task__process__init (Task__Process_Service *service,
                          Task__Process_ServiceDestroy destroy)
{
  protobuf_c_service_generated_init (&service->base,
                                     &task__process__descriptor,
                                     (ProtobufCServiceDestroy) destroy);
}
